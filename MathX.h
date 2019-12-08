#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Engine.h"

namespace penguine
{
	class MathX
	{
	public:
		static sf::Vector3f* LerpPosition(sf::Vector3f* current, sf::Vector3f* destination, float t);
		static float Lerp(float t, float a, float b);

		static float Map(float value, float min, float max, float outMin, float outMax);
		static float Map01(float value, float min, float max);

		static float Clamp(float value, float min, float max);
		static float Clamp01(float value);
	};
}
