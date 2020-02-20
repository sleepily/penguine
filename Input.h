#pragma once
#include <SFML/Graphics.hpp>
#include "PenguineObject.h"
#include "Mouse.h"

typedef sf::Vector3<bool>	Vector3b;

namespace penguine
{
	class Mouse;

	class Input: public PenguineObject
	{
	private:
		sf::Time m_LastPollTime, m_CurrentPollTime;

		Mouse* m_Mouse;

		void ConvertMouseInstructions();

	public:
		Input();
		~Input();

		virtual void Update();
		virtual void Render();

		void ResetMouseButtons();

		void PollFromEvent(sf::Event event);
		void ReadMouseButtons(sf::Event event);
		void GetReleasedButtons(sf::Event event);

		Mouse* GetMouse();
	};
}