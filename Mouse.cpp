#include <SFML/Graphics.hpp>
#include "Mouse.h"

namespace penguine
{
	Mouse::Mouse()
	{
		m_Position = new sf::Vector2i();
		m_ScrollDelta = new sf::Vector2f();
		m_Velocity = new sf::Vector2f();
	}
}
