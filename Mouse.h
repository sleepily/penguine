#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"

namespace penguine
{
	class Mouse
	{
	private:
		bool m_IsInWindow;
		bool m_ButtonDown[3], m_ButtonHold[3], m_PreviousButtonHold[3], m_ButtonUp[3];

		sf::Vector2i* m_Position;

		sf::Vector2f* m_ScrollDelta;
		sf::Vector2f* m_Velocity;

	public:
		Mouse();

		bool GetMouseDown(int button);
		bool GetMouseHold(int button);
		bool GetMouseRelease(int button);

		sf::Vector2i* GetPosition();
		sf::Vector3f* GetPosition3D();
		sf::Vector2f* GetVecolity();
		sf::Vector2f* GetScrollDelta();

		friend class Input;
	};
}