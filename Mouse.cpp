#include <SFML/Graphics.hpp>
#include "Mouse.h"

namespace penguine
{
	Mouse::Mouse()
	{
		m_Position = new sf::Vector2i();
		m_ScrollDelta = new sf::Vector2f();
		m_Velocity = new sf::Vector2f();

		memset(m_ButtonDown, 0, sizeof(m_ButtonDown));
		memset(m_ButtonHold, 0, sizeof(m_ButtonHold));
		memset(m_ButtonUp, 0, sizeof(m_ButtonUp));
	}

	sf::Vector2i* Mouse::GetPosition()
	{
		return m_Position;
	}

	sf::Vector3f* Mouse::GetPosition3D()
	{
		return new sf::Vector3f
		(
			m_Position->x,
			m_Position->y,
			0
		);
	}

	sf::Vector2f* Mouse::GetVecolity()
	{
		return m_Velocity;
	}

	sf::Vector2f* Mouse::GetScrollDelta()
	{
		return m_ScrollDelta;
	}

	bool Mouse::GetMouseDown(int button)
	{
		return m_ButtonDown[button];
	}

	bool Mouse::GetMouseHold(int button)
	{
		return m_ButtonHold[button];
	}

	bool Mouse::GetMouseRelease(int button)
	{
		return m_ButtonUp[button];
	}
}
