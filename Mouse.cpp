#include "Mouse.h"

penguine::Mouse::Mouse()
{
	m_Position = sf::Vector2i();
	m_ScrollDelta, m_Velocity = sf::Vector2f();
}
