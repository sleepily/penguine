#pragma once
#include <string>
#include "GameObject.h"
#include "PenguineObject.h"

class GameObject;

namespace penguine
{
	typedef unsigned int	uint;

	class Scene: public PenguineObject
	{
	private:
		std::vector<GameObject*>* m_GameObjects;
		bool m_IsActive;

		size_t m_SceneID;

		std::string m_Name;

		uint m_GameObjectCount;

	public:
		Scene();
		Scene(size_t id, std::string name);
		virtual ~Scene();

		virtual void Update();
		virtual void Render();

		virtual void SetEngine(Engine* engine);

		std::string GetName();
		std::vector<GameObject*>* GetGameObjects();
		void AddGameObject(GameObject* go);
		Scene* AppendGameObjectsFromScene(Scene* fromScene);

		virtual std::string ToString();

		uint GetGameObjectCount();

		Scene* SetActive(bool isActive);
	};
}