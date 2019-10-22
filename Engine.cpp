#include <iostream>
#include <string>
#include "penguine/Engine.h"

namespace penguine
{
	Engine::Engine(Scene* startScene)
	{
		m_Scenes.push_back(startScene->SetActive(true));

		InitializeComponents();
	}

	Engine::~Engine()
	{

	}

	void Engine::Start()
	{
		InitializeComponents();
		GameLoop();
	}

	void Engine::InitializeComponents()
	{
		m_Time = GameTime();
	}

	Engine* Engine::AddScene(Scene* scene)
	{
		m_Scenes.push_back(scene);

		return this;
	}

	std::vector<Scene*> Engine::GetScenes()
	{
		return m_Scenes;
	}
	
	void Engine::GameLoop()
	{
		while (m_Graphics.GetWindow()->isOpen())
		{
			m_Time.Update();

			std::cout << m_Time.GetTimeInSeconds() << std::endl;

			// Need deltaTime from last Update()
			Input();

			// Count how long it took to do Input()
			// Subtract that from the expected deltaTime for the next Frame
			// Wait that amount
			Update(m_Time.GetDeltaTime());
		}
	}

	void Engine::Input()
	{
		if (m_Graphics.GetWindow()->pollEvent(m_Event))
			if (m_Event.type == sf::Event::Closed)
				m_Graphics.GetWindow()->close();

		m_Graphics.GetWindow()->clear();
	}

	void Engine::Update(float deltaTimeInSeconds)
	{
		for (Scene* scene : m_Scenes)
		{
			for (GameObject go : scene->GetGameObjects())
			{
				if (&go == nullptr)
					continue;

				std::cout << go.ToString() << std::endl;
			}
		}
	}
}