#include <SFML/Graphics.hpp>
#include "penguine/Input.h"

typedef sf::Vector3<bool>	Vector3b;

namespace penguine
{
	Input::Input()
	{
		MousePosition = sf::Vector2u();
		MouseScrollDelta = sf::Vector2f();
		MouseVecolity = sf::Vector2f();
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

	void Input::CalculateMouseChanges()
	{
		ReadMouseButtons();
		ConvertMouseInstructions(m_MouseHold, m_MouseDown);

	}
	Vector3b Input::MouseDown()
	{
		return m_MouseDown;
	}
	Vector3b Input::MouseHold()
	{
		return m_MouseHold;
	}
	Vector3b Input::MouseRelease()
	{
		return m_MouseRelease;
	}
	void Input::ReadMouseButtons()
	{
		m_MouseDown.x = m_Mouse.isButtonPressed(sf::Mouse::Button::Left);
		m_MouseDown.y = m_Mouse.isButtonPressed(sf::Mouse::Button::Right);
		m_MouseDown.z = m_Mouse.isButtonPressed(sf::Mouse::Button::Middle);
	}

	void Input::ConvertMouseInstructions(Vector3b hold, Vector3b down)
	{
		Vector3b output();

		// Reduce to hold if mouse is down for the second time
		down.x = (!hold.x && down.x);
		down.y = (!hold.y && down.y);
		down.z = (!hold.z && down.z);

		// Calculate Holds
		hold.x = (!hold.x && down.x || hold.x && !down.x);
		hold.y = (!hold.y && down.y || hold.y && !down.y);
		hold.z = (!hold.z && down.z || hold.z && !down.z);

		// Check for releases
		m_MouseRelease.x = (m_PreviousMouseHold.x && !hold.x);
		m_MouseRelease.y = (m_PreviousMouseHold.y && !hold.y);
		m_MouseRelease.z = (m_PreviousMouseHold.z && !hold.z);

		m_MouseHold = hold;

		m_PreviousMouseHold = m_MouseHold;
	}
}