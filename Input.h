#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/PenguineObject.h"
#include "penguine/Mouse.h"

typedef sf::Vector3<bool>	Vector3b;

namespace penguine
{
	class Input: public PenguineObject
	{
		sf::Time m_LastPollTime, m_CurrentPollTime;

		penguine::Mouse m_Mouse;

		void ConvertMouseInstructions();

	public:
		Input();
		~Input();

		virtual void Update();
		virtual void Render();

		void PollFromEvent(sf::Event event);
		void ReadMouseButtons();

		bool GetMouseDown();
		bool GetMouseHold();
		bool GetMouseRelease();

		sf::Vector2u GetMousePosition();
		sf::Vector2f GetMouseVecolity();
		sf::Vector2f GetMouseScrollDelta();
	};
}