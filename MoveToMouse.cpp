#include <SFML/Graphics.hpp>
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

		m_LerpStartPosition = new sf::Vector3f;
		m_LerpEndPosition = new sf::Vector3f;
	}

	void MoveToMouse::Update()
	{
		if (!m_IsEnabled)
			return;

		Move();

		if (m_OnClick && engine->GetInput()->GetMouse()->GetMouseDown(0))
			OnClick();
	}

	void MoveToMouse::Render()
	{

	}

	void MoveToMouse::Move()
	{
		if (m_LastClick > FLT_EPSILON && m_IsLerping)
		{
			if (engine->GetTime()->GetTimeInSeconds() >= m_LastClick + m_LerpDuration)
			{
				m_IsLerping = false;
				m_LastClick = 0;

				m_GameObject->GetTransform()->position = m_LerpEndPosition;
				return;
			}

			m_GameObject->GetTransform()->position =
				MathX::LerpPosition
				(
					m_LerpStartPosition,
					m_LerpEndPosition,
					MathX::Map01(engine->GetTime()->GetTimeInSeconds(), m_LastClick, m_LastClick + m_LerpDuration)
				);
		}
	}

	sf::Vector3f* MoveToMouse::GetMouseDirection()
	{
		return m_LerpEndPosition;
	}

	void MoveToMouse::OnClick()
	{
		m_LastClick = engine->GetTime()->GetTimeInSeconds();

		m_IsLerping = true;

		m_LerpStartPosition = m_GameObject->GetTransform()->position;
		m_LerpEndPosition = engine->GetInput()->GetMouse()->GetPosition3D();
	}
}
