#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.h"

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
		ResetMouseButtons();
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

		case sf::Event::MouseButtonPressed:
			ReadMouseButtons(event);
			break;

		case sf::Event::MouseButtonReleased:
			GetReleasedButtons(event);
			ReadMouseButtons(event);
			break;

		default:
			break;
		}
	}

	Mouse* Input::GetMouse()
	{
		return m_Mouse;
	}

	void Input::GetReleasedButtons(sf::Event event)
	{
		for (int button = 0; button < 3; button++)
			if (event.mouseButton.button == (sf::Mouse::Button)button)
				m_Mouse->m_ButtonRelease[button] = true;
	}

	void Input::ReadMouseButtons(sf::Event event)
	{
		for (int button = 0; button < 3; button++)
		{
			// Get mouse press through AND
			if (!m_Mouse->m_ButtonPressed[button] && !m_Mouse->m_PreviousButtonHold[button])
				m_Mouse->m_ButtonPressed[button] = sf::Mouse::isButtonPressed((sf::Mouse::Button)button);

			if (m_Mouse->m_ButtonPressed[button] && m_Mouse->m_PreviousButtonHold[button])
				m_Mouse->m_ButtonPressed[button] = false;

			if (m_Mouse->m_ButtonPressed[button] && !m_Mouse->m_PreviousButtonHold[button])
				m_Mouse->m_ButtonHold[button] = true;

			if (m_Mouse->m_ButtonRelease[button])
				m_Mouse->m_ButtonHold[button] = false;
		}

		std::cout << std::endl << "Down    ";

		for (int b = 0; b < 3; b++)
			std::cout << m_Mouse->m_ButtonPressed[b] << " ";

		std::cout << std::endl << "Hold    ";

		for (int b = 0; b < 3; b++)
			std::cout << m_Mouse->m_ButtonHold[b] << " ";

		std::cout << std::endl << "Release ";

		for (int b = 0; b < 3; b++)
			std::cout << m_Mouse->m_ButtonRelease[b] << " ";

		std::cout << std::endl;
	}

	void Input::ConvertMouseInstructions()
	{

		for (int i = 0; i < 3; i++)
		{
			// Reduce to m_Mouse->m_ButtonHold if mouse is m_Mouse->m_ButtonDown for the second time
			if (m_Mouse->m_PreviousButtonHold[i])
				m_Mouse->m_ButtonPressed[i] = false;

			// Calculate m_Mouse->m_ButtonHolds
			m_Mouse->m_ButtonHold[i] =
				(
					!m_Mouse->m_PreviousButtonHold[i] && m_Mouse->m_ButtonPressed[i] ||
					m_Mouse->m_PreviousButtonHold[i] && !m_Mouse->m_ButtonRelease[i]
				);

			// Check for releases
			m_Mouse->m_ButtonRelease[i] = (m_Mouse->m_PreviousButtonHold[i] && !m_Mouse->m_ButtonPressed[i]);
		}
	}

	void Input::ResetMouseButtons()
	{
		for (int i = 0; i < 3; i++)
			m_Mouse->m_PreviousButtonHold[i] = m_Mouse->m_ButtonHold[i];

		for (int i = 0; i < 3; i++)
		{
			if (m_Mouse->m_ButtonRelease[i])
				m_Mouse->m_ButtonHold[i] = false;

			m_Mouse->m_ButtonPressed[i] = false;
			m_Mouse->m_ButtonRelease[i] = false;
		}
	}
}