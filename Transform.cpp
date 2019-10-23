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
}
