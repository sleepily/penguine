#include "Scene.h"


namespace penguine
{
	Scene::Scene()
	{
		m_IsActive = true;
		m_GameObjectCount = 0;
	}

	Scene::~Scene()
	{

	}

	void Scene::AddGameObject(GameObject* go)
	{
		m_GameObjects.push_back(*go);
		m_GameObjectCount++;
	}

	std::vector<GameObject> Scene::GetGameObjects()
	{
		return m_GameObjects;
	}

	Scene* Scene::AppendGameObjectsFromScene(Scene* fromScene)
	{
		for (GameObject go : fromScene->GetGameObjects())
			this->m_GameObjects.push_back(go);

		return this;
	}

	uint Scene::GetGameObjectCount()
	{
		return m_GameObjectCount;
	}

	Scene* Scene::SetActive(bool isActive)
	{
		m_IsActive = isActive;
		return this;
	}
}
