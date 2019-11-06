#include <iostream>
#include "Scene.h"

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
#ifdef PENGUINE_DEBUG
		std::cout << "Updating Scene..." << std::endl;
#endif

		for (GameObject* go : *m_GameObjects)
			go->Update();

#ifdef PENGUINE_DEBUG
		std::cout << "Updated Scene." << std::endl;
#endif
	}

	void Scene::Render()
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Rendering Scene..." << std::endl;
#endif

		for (GameObject* go : *m_GameObjects)
			go->Render();
	}

	void Scene::SetEngine(Engine* engine)
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Setting Scene Engine..." << std::endl;
#endif
		this->engine = engine;

		for (GameObject* go : *m_GameObjects)
			go->SetEngine(engine);
	}

	void Scene::AddGameObject(GameObject* go)
	{
#ifdef PENGUINE_DEBUG
		std::cout << "Adding GameObject " << go->GetName() << " to Scene " << m_Name << std::endl;
#endif

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
