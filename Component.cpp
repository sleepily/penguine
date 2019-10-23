#include "penguine/Component.h"

namespace penguine
{
	Component::Component()
	{
		m_Name = "DefaultComponent";
	}

	Component::~Component()
	{

	}

	void Component::Update()
	{
		
	}

	void Component::Render()
	{

	}

	std::string Component::ToString()
	{
		return m_Name;
	}
}