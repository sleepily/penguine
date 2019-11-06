#include "penguine/MoveToMouse.h"
#include "penguine/Engine.h"
#include "penguine/Mouse.h"

penguine::MoveToMouse::MoveToMouse()
{
	m_Name = "MoveToMouse";
	m_IsEnabled = true;
	m_ScrollOffset = new sf::Vector2f();
}

void penguine::MoveToMouse::Update()
{
	if (!m_IsEnabled)
		return;

	penguine::Mouse* mouse = engine->GetInput()->GetMouse();

	m_ScrollOffset->x += (int)mouse->GetScrollDelta()->x;
	m_ScrollOffset->y += (int)mouse->GetScrollDelta()->y;

	m_GameObject->GetTransform()->position =
		new sf::Vector3f
		(
			mouse->GetPosition()->x + m_ScrollOffset->x * 10.0f,
			mouse->GetPosition()->y + m_ScrollOffset->y * 10.0f,
			m_GameObject->GetTransform()->position->z
		);
}

void penguine::MoveToMouse::Render()
{

}
