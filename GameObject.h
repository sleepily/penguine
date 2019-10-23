#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "penguine/Component.h"
#include "penguine/PenguineObject.h"

namespace penguine
{
	class Component;
	class Scene;

	class GameObject: public PenguineObject
	{
	protected:
		std::string m_Name;
		std::string m_Type;

		sf::Transform* m_Transform;

		Scene* m_Scene;

		std::vector<Component*>* m_Components;

	public:
		GameObject();
		GameObject(Scene* scene);
		virtual ~GameObject();

		std::string GetName();

		virtual void Update();

		sf::Transform* GetTransform();
		std::vector<Component*>* GetComponents();

		Component* AddComponent(Component* component);

		std::string ToString();

		friend class Component;
	};
}