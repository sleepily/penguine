#pragma once
#include <string>
#include "penguine/GameObject.h"
#include "penguine/PenguineObject.h"
typedef unsigned int	uint;

class GameObject;

namespace penguine
{
	class Scene: public PenguineObject
	{
	private:
		std::vector<GameObject> m_GameObjects;
		bool m_IsActive;

		size_t m_SceneID;

		std::string m_Name;

		uint m_GameObjectCount;

	public:
		Scene();
		virtual ~Scene();

		virtual void Update();
		virtual void Render();

		std::string GetName();
		std::vector<GameObject> GetGameObjects();
		void AddGameObject(GameObject* go);
		Scene* AppendGameObjectsFromScene(Scene* fromScene);

		uint GetGameObjectCount();

		Scene* SetActive(bool isActive);
	};
}