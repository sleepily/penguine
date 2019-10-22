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

	std::string Component::GetName()
	{
		return m_Name;
	}
}