#include <iostream>
#include <SFML/Graphics.hpp>
#include "penguine/Input.h"
#include "penguine/Mouse.h"

namespace penguine
{
	Input::Input()
	{
		m_Mouse = new penguine::Mouse();
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
		m_Mouse->m_ScrollDelta = new sf::Vector2f();

		switch (event.type)
		{
		case sf::Event::MouseWheelScrolled:

			if (!m_Mouse->m_IsInWindow)
				break;

			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				m_Mouse->m_ScrollDelta->y = event.mouseWheelScroll.delta;
			else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
				m_Mouse->m_ScrollDelta->x = event.mouseWheelScroll.delta;

			break;

		case sf::Event::MouseMoved:

			if (!m_Mouse->m_IsInWindow)
				break;

			m_Mouse->m_Position->x = event.mouseMove.x;
			m_Mouse->m_Position->y = event.mouseMove.y;

			break;

		case sf::Event::MouseLeft:

			m_Mouse->m_IsInWindow = false;
			// m_Mouse->m_Position = new sf::Vector2i();

			break;

		case sf::Event::MouseEntered:

			m_Mouse->m_IsInWindow = true;
			m_Mouse->m_Position->x = event.mouseMove.x;
			m_Mouse->m_Position->y = event.mouseMove.y;

			break;

		default:
			break;
		}

		ReadMouseButtons();
		ConvertMouseInstructions();
	}

	bool Input::GetMouseDown()
	{
		return m_Mouse->m_ButtonDown;
	}

	bool Input::GetMouseHold()
	{
		return m_Mouse->m_ButtonHold;
	}

	bool Input::GetMouseRelease()
	{
		return m_Mouse->m_ButtonRelease;
	}

	sf::Vector2i* Input::GetMousePosition()
	{
		std::cout << "Mouse Position: " << m_Mouse->m_Position->x << "x, " << m_Mouse->m_Position->y << "y. " << std::endl;

		return m_Mouse->m_Position;
	}

	sf::Vector2f* Input::GetMouseVecolity()
	{
		return m_Mouse->m_Velocity;
	}

	sf::Vector2f* Input::GetMouseScrollDelta()
	{
		return m_Mouse->m_ScrollDelta;
	}

	void Input::ReadMouseButtons()
	{
		m_Mouse->m_ButtonDown[0] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		m_Mouse->m_ButtonDown[1] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
		m_Mouse->m_ButtonDown[2] = sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle);
	}

	void Input::ConvertMouseInstructions()
	{
		for (int i = 0; i < 3; i++)
		{
			// Reduce to m_Mouse->m_ButtonHold if mouse is m_Mouse->m_ButtonDown for the second time
			m_Mouse->m_ButtonDown[i] = (!m_Mouse->m_ButtonHold[i] && m_Mouse->m_ButtonDown[i]);

			// Calculate m_Mouse->m_ButtonHolds
			m_Mouse->m_ButtonHold[i] = (!m_Mouse->m_ButtonHold[i] && m_Mouse->m_ButtonDown[i] || m_Mouse->m_ButtonHold[i] && !m_Mouse->m_ButtonDown[i]);

			// Check for releases
			m_Mouse->m_ButtonRelease[i] = (!m_Mouse->m_ButtonDown[i] && !m_Mouse->m_ButtonHold[i]);
		}
	}
}