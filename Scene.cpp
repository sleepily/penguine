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
		m_GameObjects = new std::vector<GameObject*>();
	}

	Scene::~Scene()
	{

	}

	void Scene::Update()
	{
		for (GameObject* go : *m_GameObjects)
			go->Update();
	}

	void Scene::Render()
	{
		for (GameObject* go : *m_GameObjects)
			go->Render();
	}

	void Scene::SetEngine(Engine* engine)
	{
		this->engine = engine;

		for (GameObject* go : *m_GameObjects)
			go->SetEngine(engine);
	}

	void Scene::AddGameObject(GameObject* go)
	{
		std::cout << "Adding GameObject " << go->GetName() << " to Scene " << m_Name << std::endl;
		go->engine = engine;
		m_GameObjects->push_back(go);
		m_GameObjectCount++;
	}

	std::string Scene::GetName()
	{
		return m_Name;
	}

	std::vector<GameObject*>* Scene::GetGameObjects()
	{
		return m_GameObjects;
	}

	Scene* Scene::AppendGameObjectsFromScene(Scene* fromScene)
	{
		for (GameObject* go : *fromScene->GetGameObjects())
			m_GameObjects->push_back(go);

		return this;
	}

	std::string Scene::ToString()
	{
		std::string output;

		for (GameObject* go : *m_GameObjects)
			output += go->ToString();

		return output;
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
