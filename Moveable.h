#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace penguine
{
	class Component;

	class Moveable: public Component
	{
	private:
		sf::Vector3f* m_MovementDelta;

	public:
		Moveable();
		~Moveable();

		enum class MovementType
		{
			STATIC,
			BOUNCE_H,
			BOUNCE_V,
			ORBIT
		};

		MovementType movementType;

		float speed;
		float amplitude;

		virtual void Update();

		virtual std::string ToString();
	};
}