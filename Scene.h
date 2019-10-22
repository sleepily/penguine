#pragma once
#include "penguine/GameObject.h"

class GameObject;

namespace penguine
{
	class Scene
	{
	private:
		std::vector<GameObject> m_GameObjects;
		bool m_IsActive;

	public:
		Scene();
		virtual ~Scene();

		std::vector<GameObject> GetGameObjects();
		Scene* AppendGameObjectsFromScene(Scene fromScene);

		Scene* SetActive(bool isActive);
	};
}