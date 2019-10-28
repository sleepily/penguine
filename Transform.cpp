#include <string>
#include <SFML/Graphics.hpp>
#include "penguine/Transform.h"

namespace penguine
{
	Transform::Transform()
	{
		position = new sf::Vector3f();
		rotation = new sf::Vector3f();
		scale = new sf::Vector3f(1.0f, 1.0f, 1.0f);
	}

	Transform::~Transform()
	{

	}

	sf::Vector2f* Transform::position2D()
	{
		return new sf::Vector2f(position->x, position->y);
	}

	sf::Vector3f* Transform::Translate(sf::Vector3f* delta)
	{
		position->x += delta->x;
		position->y += delta->y;
		position->z += delta->z;

		return position;
	}

	std::string Transform::ToString()
	{
		std::string output;
		output += "Position: " + std::to_string(position->x) + "x, " + std::to_string(position->y) + "y, " + std::to_string(position->z) + "z. ";
		output += "Rotation: " + std::to_string(rotation->x) + "x, " + std::to_string(rotation->y) + "y, " + std::to_string(rotation->z) + "z. ";
		return output;
	}
}
