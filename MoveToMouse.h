#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

namespace penguine
{
	class MoveToMouse: public Component
	{
	public:
		MoveToMouse();
		
		virtual void Update();
		virtual void Render();
	};
}