#include <string>
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "Component.h"
#include "Scene.h"
#include "Transform.h"

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

	void GameObject::SetEngine(Engine* engine)
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Set GameObject " + m_Name +" to main engine" << std::endl;
#endif

		this->engine = engine;

		for (Component* component : *m_Components)
			component->engine = engine;
	}

	void GameObject::Update()
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Updating GameObject: " << std::endl;
		std::cout << ToString() << std::endl;
#endif

		for (Component* component : *m_Components)
			component->Update();
	}

	void GameObject::Render()
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Rendering GameObject: " << m_Name << "..." << std::endl;
#endif

		for (Component* component : *m_Components)
			component->Render();
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
		std::cout << "Added Component " << component->GetName() << " to " << m_Name << ". " << std::endl;
#endif

		return component;
	}

	Component* GameObject::GetComponent(std::string name)
	{

		return NULL;
	}

	void GameObject::CallActionComponents(std::string actionType)
	{
		for (Component* actionComponent : *m_Components)
			actionComponent->DoAction(actionType);
	}

	std::string GameObject::ToString()
	{
		std::string outputString;
		size_t componentCount = m_Components->size();

		outputString += "Name: \t" + m_Name + "\n";
		outputString += "Components: \t" + std::to_string(componentCount) + ";\n";

		for (Component* component : *m_Components)
			outputString += "\t" + component->ToString() + "\n";

		return outputString;
	}
}