#include "Scene.h"
#include <iostream>

namespace penguine
{
	Scene::Scene()
	{
		m_Name = "SampleScene";
		m_IsActive = true;
		m_GameObjectCount = 0;
		m_SceneID = 1;
	}

	Scene::~Scene()
	{

	}

	void Scene::Update()
	{
		for (GameObject go : m_GameObjects)
		{
			if (&go == nullptr)
				continue;

			go.Update();

#if PENGUINE_DEBUG
			std::cout << go.ToString() << std::endl;
#endif
		}
	}

	void Scene::Render()
	{
		for (GameObject go : m_GameObjects)
		{
			if (&go == nullptr)
				continue;

			go.Render();

#if PENGUINE_DEBUG
			std::cout << go.ToString() << std::endl;
#endif
		}
	}

	void Scene::AddGameObject(GameObject* go)
	{
		std::cout << "Adding GameObject " << go->GetName() << " to Scene " << m_Name << std::endl;
		m_GameObjects.push_back(*go);
		m_GameObjectCount++;
	}

	std::string Scene::GetName()
	{
		return m_Name;
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
