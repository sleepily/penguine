#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "penguine/Component.h"

using namespace sf;

namespace penguine
{
	class Component;

	class GameObject
	{
	protected:
		std::string m_Name;
		std::string m_Type;

		Transform* m_Transform;

		std::vector<Component*> m_Components;

	public:
		GameObject();
		virtual ~GameObject();

		Transform* GetTransform();
		std::vector<Component*> GetComponents();

		bool AddComponent(Component* component);

		std::string ToString();

		friend class Component;
	};
}