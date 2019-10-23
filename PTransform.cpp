#include <SFML/Graphics.hpp>
#include "penguine/PTransform.h"

namespace penguine
{
	class Component;

	PTransform::PTransform()
	{
		m_Position = new sf::Vector3f();
		m_Rotation = new sf::Vector3f();
	}

	PTransform::~PTransform()
	{
	}

	sf::Vector3f* PTransform::GetPosition()
	{
		return m_Position;
	}

	sf::Vector3f* PTransform::GetRotation()
	{
		return m_Rotation;
	}

	sf::Vector3f* PTransform::SetPosition(float x, float y, float z)
	{
		m_Position = new sf::Vector3f(x, y, z);
		return m_Position;
	}

	sf::Vector3f* PTransform::SetRotation(float x, float y, float z)
	{
		m_Rotation = new sf::Vector3f(x, y, z);
		return m_Rotation;
	}
}
