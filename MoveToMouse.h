#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace penguine
{
	class MoveToMouse: public Component
	{
	private:
		sf::Vector2f* m_ScrollOffset;

	public:
		MoveToMouse();
		
		virtual void Update();
		virtual void Render();
	};
}