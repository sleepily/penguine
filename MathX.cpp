#include "MathX.h"

namespace penguine
{
	sf::Vector3f* MathX::LerpPosition(sf::Vector3f* current, sf::Vector3f* destination, float t)
	{
		return new sf::Vector3f
		(
			Lerp(t, current->x, destination->x),
			Lerp(t, current->y, destination->y),
			Lerp(t, current->z, destination->z)
		);
	}

	float MathX::Lerp(float t, float a, float b)
	{
		return a + (t * (b - a));
	}

	float MathX::Map(float value, float min, float max, float outMin, float outMax)
	{
		return (value - min) / (max - min) * (outMax - outMin) + outMin;
	}

	float MathX::Map01(float value, float min, float max)
	{
		return Map(value, min, max, 0, 1);
	}

	float MathX::Clamp(float value, float min, float max)
	{
		if (value <= min)
			return min;

		if (value >= max)
			return max;

		return value;
	}

	float MathX::Clamp01(float value)
	{
		return Clamp(value, 0, 1);
	}
}