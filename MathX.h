#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"

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

		static sf::Vector2f V2iToV2f(sf::Vector2i vector);
		static sf::Vector2i V2fToV2i(sf::Vector2f vector);
	};
}
