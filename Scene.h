#pragma once
#include "penguine/GameObject.h"

class GameObject;

typedef unsigned int	uint;

namespace penguine
{
	class Scene
	{
	private:
		std::vector<GameObject> m_GameObjects;
		bool m_IsActive;

		uint m_GameObjectCount;

	public:
		Scene();
		virtual ~Scene();


		std::vector<GameObject> GetGameObjects();
		void AddGameObject(GameObject* go);
		Scene* AppendGameObjectsFromScene(Scene* fromScene);

		uint GetGameObjectCount();

		Scene* SetActive(bool isActive);
	};
}