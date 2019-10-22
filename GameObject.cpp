#include <string>
#include <vector>
#include "penguine/GameObject.h"
#include "penguine/Component.h"

using namespace sf;

namespace penguine
{
	GameObject::GameObject()
	{
		m_Name = "NewGameObject";
	}

	GameObject::~GameObject()
	{

	}

	Transform* GameObject::GetTransform()
	{
		return this->m_Transform;
	}

	std::vector<Component*> GameObject::GetComponents()
	{
		return m_Components;
	}

	bool GameObject::AddComponent(Component* component)
	{
		component->m_GameObject = this;
		m_Components.push_back(component);
		return true;
	}

	std::string GameObject::ToString()
	{
		std::string outputString;
		size_t componentCount = m_Components.size();

		outputString += "GameObject: " + m_Name + "\n";
		outputString += "Components: " + std::to_string(componentCount) + ";\n";

		for (Component* component : m_Components)
		{
			outputString += "\t" + component->GetName() + "\n";
		}

		return outputString;
	}
}