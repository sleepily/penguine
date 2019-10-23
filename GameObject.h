#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "penguine/Component.h"
#include "penguine/PenguineObject.h"
#include "penguine/Transform.h"

namespace penguine
{
	class Scene;
	class Component;
	class Transform;

	class GameObject: public PenguineObject
	{
	protected:
		std::string m_Type;

		Transform* m_Transform;

		Scene* m_Scene;

		std::vector<Component*>* m_Components;

	public:
		GameObject();
		GameObject(Scene* scene);
		virtual ~GameObject();

		virtual void Update();
		virtual void Render();

		virtual void SetEngine(Engine* engine);

		Transform* GetTransform();
		std::vector<Component*>* GetComponents();

		Component* AddComponent(Component* component);

		virtual std::string ToString();

		friend class Component;
	};
}