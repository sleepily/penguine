#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

using namespace sf;

namespace penguine
{
	class PTransform : public Component
	{
	private:
		Vector3f* m_Position;
		Vector3f* m_Rotation;

	public:
		PTransform();
		virtual ~PTransform();

		Vector3f* GetPosition();
		Vector3f* GetRotation();

		Vector3f* SetPosition(float x, float y, float z);
		Vector3f* SetRotation(float x, float y, float z);
	};
}