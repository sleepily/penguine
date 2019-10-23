#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

namespace penguine
{
	class PTransform : public Component
	{
	private:
		sf::Vector3f* m_Position;
		sf::Vector3f* m_Rotation;

	public:
		PTransform();
		virtual ~PTransform();

		sf::Vector3f* GetPosition();
		sf::Vector3f* GetRotation();

		sf::Vector3f* SetPosition(float x, float y, float z);
		sf::Vector3f* SetRotation(float x, float y, float z);
	};
}