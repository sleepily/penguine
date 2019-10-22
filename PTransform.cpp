#include <SFML/Graphics.hpp>
#include "penguine/PTransform.h"

using namespace sf;

namespace penguine
{
	class Component;

	PTransform::PTransform()
	{
		m_Position = new Vector3f();
		m_Rotation = new Vector3f();
	}

	PTransform::~PTransform()
	{
	}

	Vector3f* PTransform::GetPosition()
	{
		return m_Position;
	}

	Vector3f* PTransform::GetRotation()
	{
		return m_Rotation;
	}

	Vector3f* PTransform::SetPosition(float x, float y, float z)
	{
		m_Position = new Vector3f(x, y, z);
		return m_Position;
	}

	Vector3f* PTransform::SetRotation(float x, float y, float z)
	{
		m_Rotation = new Vector3f(x, y, z);
		return m_Rotation;
	}
}
