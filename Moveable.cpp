#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Moveable.h"
#include "Engine.h"

namespace penguine
{
	Moveable::Moveable()
	{
		movementType = MovementType::BOUNCE_H;
		m_MovementDelta = new sf::Vector3f();
		amplitude = 1.0f;
		speed = 1.0f;
		m_Name = "Moveable";
		m_IsEnabled = true;
	}

	Moveable::~Moveable()
	{

	}

	void Moveable::Update()
	{
		if (!m_IsEnabled)
			return;

		float time = engine->GetTime()->GetTimeInSeconds();

		switch (movementType)
		{
		case MovementType::STATIC:
			m_MovementDelta = new sf::Vector3f();
			break;
		case MovementType::BOUNCE_H:
			m_MovementDelta->x = std::cos(time * speed) * amplitude * speed;
			break;
		case MovementType::BOUNCE_V:
			m_MovementDelta->y = std::cos(time * speed) * amplitude * speed;
			break;
		case MovementType::ORBIT:
			m_MovementDelta->x = std::cos(time * speed) * amplitude * speed;
			m_MovementDelta->y = std::sin(time * speed) * amplitude * speed;
			break;
		default:
			break;
		}

		m_GameObject->GetTransform()->Translate(m_MovementDelta);

#ifdef PENGUINE_DEBUG
		std::cout << "Updated " << ToString() << "..." << std::endl;
		std::cout << "\tMovement Delta: {" << std::to_string(m_MovementDelta->x) + ", " << std::to_string(m_MovementDelta->y) << "} " << std::endl;
#endif // PENGUINE_DEBUG

	}

	std::string Moveable::ToString()
	{
		return m_Name;
	}
}
