#include <string>
#include <vector>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Component.h"
#include "penguine/Scene.h"
#include "penguine/Transform.h"

namespace penguine
{
	class Transform;
	class Scene;
	class Component;

	GameObject::GameObject()
	{
		m_Name = "Default GameObject";
		m_Transform = new Transform();

		m_Scene = NULL;
		m_Components = new std::vector<Component*>();
	}

	GameObject::GameObject(Scene* scene)
	{
		m_Name = "Default GameObject";
		m_Transform = new Transform();

		m_Components = new std::vector<Component*>();

		m_Scene = scene;
		scene->AddGameObject(this);
	}

	GameObject::~GameObject()
	{

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

	void GameObject::SetEngine(Engine* engine)
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Set GameObject " + m_Name +" to main engine" << std::endl;
#endif

		this->engine = engine;

		for (Component* component : *m_Components)
			component->engine = engine;
	}

	Transform* GameObject::GetTransform()
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
		component->engine = engine;
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
			outputString += "\t" + component->ToString() + "\n";

		return outputString;
	}
}