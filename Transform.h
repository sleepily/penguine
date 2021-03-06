#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace penguine
{
	class Transform
	{
	private:
		std::string m_Name;

	public:
		Transform();
		virtual ~Transform();

		sf::Vector3f* position;
		sf::Vector3f* rotation;
		sf::Vector3f* scale;

		sf::Vector2f* position2D();

		virtual void Update();

		sf::Vector3f* Translate(sf::Vector3f* delta);

		std::string ToString();
	};
}