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
		sf::Time m_LastPollTime, m_CurrentPollTime;

		penguine::Mouse* m_Mouse;

		void ConvertMouseInstructions();

	public:
		Input();
		~Input();

		virtual void Update();
		virtual void Render();

		void PollFromEvent(sf::Event event);
		void ReadMouseButtons();

		penguine::Mouse* GetMouse();
	};
}