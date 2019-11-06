#include <string>
#include <SFML/Graphics.hpp>
#include "Transform.h"

namespace penguine
{
	Transform::Transform()
	{
		m_Name = "Transform";
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

	void Transform::Update()
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Updated " << m_Name << std::endl;
		std::cout << "\tPosition: " << std::to_string(position->x) << "x, " << std::to_string(position->y) << "y, " + std::to_string(position->z) << "z. \n" << std::endl;
		std::cout << "\tRotation: " << std::to_string(rotation->x) << "x, " << std::to_string(rotation->y) << "y, " + std::to_string(rotation->z) << "z. " << std::endl;
#endif // PENGUINE_DEBUG

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
		return m_Name;
	}
}
