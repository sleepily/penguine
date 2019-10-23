#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

namespace penguine
{
	class Transform
	{
	public:
		Transform();
		virtual ~Transform();

		sf::Vector3f* position;
		sf::Vector3f* rotation;
		sf::Vector3f* scale;
	};
}