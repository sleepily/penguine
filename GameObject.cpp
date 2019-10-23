#include <string>
#include <vector>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Component.h"
#include "penguine/Scene.h"

namespace penguine
{
	class Scene;

	GameObject::GameObject()
	{
		m_Name = "Default GameObject";
		m_Transform = new sf::Transform();
		m_Scene = NULL;
		m_Components = new std::vector<Component*>();
	}

	GameObject::GameObject(Scene* scene)
	{
		m_Name = "Default GameObject";
		m_Transform = new sf::Transform();
		m_Components = new std::vector<Component*>();

		m_Scene = scene;
		scene->AddGameObject(this);
	}

	GameObject::~GameObject()
	{

	}

	std::string GameObject::GetName()
	{
		return m_Name;
	}

	void GameObject::Update()
	{
		for (Component* component : *m_Components)
			component->Update();
	}

	void GameObject::Render()
	{
		for (Component* component : *m_Components)
			component->Render();
	}

	sf::Transform* GameObject::GetTransform()
	{
		return m_Transform;
	}

	std::vector<Component*>* GameObject::GetComponents()
	{
		return m_Components;
	}

	Component* GameObject::AddComponent(Component* component)
	{
		component->m_GameObject = this;
		m_Components->push_back(component);

#if PENGUINE_DEBUG
		std::cout << "Added component " << component->GetName() << " to " << m_Name << ". " << std::endl << std::endl;
#endif

		return component;
	}

	std::string GameObject::ToString()
	{
		std::string outputString;
		size_t componentCount = m_Components->size();

		outputString += "GameObject: " + m_Name + "\n";
		outputString += "Components: " + std::to_string(componentCount) + ";\n";

		for (Component* component : *m_Components)
			outputString += "\t" + component->GetName() + "\n";

		return outputString;
	}
}