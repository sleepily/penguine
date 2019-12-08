#include "MoveToMouse.h"
#include "Engine.h"
#include "Mouse.h"

namespace penguine
{
	MoveToMouse::MoveToMouse()
	{
		m_Name = "MoveToMouse";
		m_IsEnabled = true;
		m_OnClick = true;

		sf::Vector2i* mousePos = engine->GetInput()->GetMouse()->GetPosition();

		m_LerpPosition = new sf::Vector3f(mousePos->x, mousePos->y, 0);
	}

	void MoveToMouse::Update()
	{
		if (!m_IsEnabled)
			return;

		if (m_LastClick > FLT_EPSILON && m_IsLerping)
		{
			// lerp current position towards lerpPosition by lerpDuration
			float timeSinceLastClick = m_LastClick - engine->GetTime()->GetTimeInSeconds();

			if (timeSinceLastClick > 0)
				m_GameObject->GetTransform()->position =
				MathX::LerpPosition
				(
					m_GameObject->GetTransform()->position,
					m_LerpPosition,
					MathX::Map01(m_LastClick - engine->GetTime()->GetTimeInSeconds(), 0, m_LerpDuration)
				);
			else
			{
				m_GameObject->GetTransform()->position = m_LerpPosition;
				m_IsLerping = false;
			}
		}

		if (m_OnClick && engine->GetInput()->GetMouse()->GetMouseDown())
			OnClick();
	}

	void MoveToMouse::Render()
	{

	}

	void MoveToMouse::OnClick()
	{
		sf::Vector2i* position = engine->GetInput()->GetMouse()->GetPosition();

		m_LastClick = engine->GetTime()->GetTimeInSeconds();

		m_IsLerping = true;
		m_LerpPosition = new sf::Vector3f(position->x, position->y, 0);
	}
}
