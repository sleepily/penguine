#include "Scene.h"


namespace penguine
{
	Scene::Scene()
	{
		m_IsActive = true;
	}

	Scene::~Scene()
	{

	}

	std::vector<GameObject> Scene::GetGameObjects()
	{
		return m_GameObjects;
	}

	Scene* Scene::AppendGameObjectsFromScene(Scene fromScene)
	{
		for (GameObject go : fromScene.GetGameObjects())
			this->m_GameObjects.push_back(go);

		return this;
	}

	Scene* Scene::SetActive(bool isActive)
	{
		m_IsActive = isActive;
		return this;
	}
}
