#include <SFML/Graphics.hpp>
#include "penguine/Input.h"
#include "penguine/Mouse.h"

typedef sf::Vector3<bool>	Vector3b;

namespace penguine
{
	Input::Input()
	{
		m_Mouse = penguine::Mouse();
	}

	Input::~Input()
	{

	}

	void Input::Update()
	{

	}

	void Input::Render()
	{

	}

	void Input::PollFromEvent(sf::Event event)
	{
		if (event.type == sf::Event::MouseWheelMoved)
		{
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				std::cout << "wheel type: vertical" << std::endl;
			else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
				std::cout << "wheel type: horizontal" << std::endl;

			// m_Mouse. something = event.mouseWheelScroll.delta;
		}

		ReadMouseButtons();
		ConvertMouseInstructions();
	}

	bool Input::GetMouseDown()
	{
		return m_Mouse.m_ButtonDown;
	}

	bool Input::GetMouseHold()
	{
		return m_Mouse.m_ButtonHold;
	}

	bool Input::GetMouseRelease()
	{
		return m_Mouse.m_ButtonRelease;
	}

	sf::Vector2u Input::GetMousePosition()
	{
		return m_Mouse.m_Position;
	}

	sf::Vector2f Input::GetMouseVecolity()
	{
		return m_Mouse.m_Velocity;
	}

	sf::Vector2f Input::GetMouseScrollDelta()
	{
		return m_Mouse.m_ScrollDelta;
	}

	void Input::ReadMouseButtons()
	{
		m_Mouse.m_ButtonDown[0] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		m_Mouse.m_ButtonDown[1] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
		m_Mouse.m_ButtonDown[2] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle);
	}

	void Input::ConvertMouseInstructions()
	{
		Vector3b output();

		for (int i = 0; i < 3; i++)
		{
			// Reduce to m_Mouse->m_ButtonHold if mouse is m_Mouse->m_ButtonDown for the second time
			m_Mouse.m_ButtonDown[i] = (!m_Mouse.m_ButtonHold[i] && m_Mouse.m_ButtonDown[i]);

			// Calculate m_Mouse->m_ButtonHolds
			m_Mouse.m_ButtonHold[i] = (!m_Mouse.m_ButtonHold[i] && m_Mouse.m_ButtonDown[i] || m_Mouse.m_ButtonHold[i] && !m_Mouse.m_ButtonDown[i]);

			// Check for releases
			m_Mouse.m_ButtonRelease[i] = (!m_Mouse.m_ButtonDown[i] && !m_Mouse.m_ButtonHold[i]);
		}
	}
}