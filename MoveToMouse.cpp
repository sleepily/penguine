#include "penguine/MoveToMouse.h"
#include "penguine/Engine.h"

penguine::MoveToMouse::MoveToMouse()
{
	m_Name = "MoveToMouse";
	m_IsEnabled = true;
}

void penguine::MoveToMouse::Update()
{
	if (!m_IsEnabled)
		return;

	sf::Vector2i* mousePos = engine->GetInput()->GetMousePosition();
	sf::Vector3f* pos = m_GameObject->GetTransform()->position;

	m_GameObject->GetTransform()->position = new sf::Vector3f(mousePos->x, mousePos->y, pos->z);
}

void penguine::MoveToMouse::Render()
{

}
