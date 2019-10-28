#include "penguine/Engine.h"
#include "PenguineObject.h"

namespace penguine
{
	PenguineObject::PenguineObject()
	{
		engine = nullptr;
	}

	PenguineObject::~PenguineObject()
	{
	}

	void PenguineObject::Update()
	{
	}

	void PenguineObject::Render()
	{
	}

	void PenguineObject::SetEngine(Engine* engine)
	{
		this->engine = engine;
	}

	std::string PenguineObject::ToString()
	{
		return GetName();
	}

	std::string PenguineObject::GetName()
	{
		return m_Name;
	}
}