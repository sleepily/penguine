#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/PenguineObject.h"

typedef sf::Vector3<bool>	Vector3b;

namespace penguine
{
	class Input: public PenguineObject
	{
		sf::Time m_LastPollTime, m_CurrentPollTime;
		Vector3b m_MouseDown, m_MouseHold, m_PreviousMouseHold, m_MouseRelease;

		sf::Mouse m_Mouse;

		void ConvertMouseInstructions(Vector3b hold, Vector3b down);

	public:
		Input();
		~Input();

		virtual void Update();
		virtual void Render();

		void ReadMouseButtons();
		void CalculateMouseChanges();

		Vector3b MouseDown();
		Vector3b MouseHold();
		Vector3b MouseRelease();

		sf::Vector2u MousePosition;
		sf::Vector2f MouseVecolity;
		sf::Vector2f MouseScrollDelta;
	};
}