#include "Component.h"

namespace penguine
{
	Component::Component()
	{
		m_Name = "Default Component";
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

	void Component::DoAction(std::string actionType)
	{
		// In implemented components, check for activation of action by action type
	}

	void Component::SetActionType(std::string type)
	{
		m_ActionType = type;
	}

	std::string Component::ToString()
	{
		return m_Name;
	}
}