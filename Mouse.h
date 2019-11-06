#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Input.h"

namespace penguine
{
	class Mouse
	{
	private:
		bool m_ButtonDown[3], m_ButtonHold[3], m_PreviousButtonHold[3], m_ButtonRelease[3];

		sf::Vector2u m_Position;

		sf::Vector2f m_ScrollDelta, m_Velocity;

	public:
		friend class Input;
	};
}