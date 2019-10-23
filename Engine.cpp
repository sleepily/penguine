#include <iostream>
#include <string>
#include "penguine/Engine.h"

#define PENGUINE_DEBUG	true

namespace penguine
{
	Engine::Engine(Scene* startScene)
	{
		m_Scenes.push_back(startScene->SetActive(true));
		m_Event = new Event();
		m_Time = new GameTime();
		m_Graphics = new Graphics(400, 400);
	}

	Engine::~Engine()
	{

	}

	void Engine::Start()
	{
		GameLoop();
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
		while (m_Graphics->GetWindow()->isOpen())
		{
			m_Time->Update();

			Input();

#if PENGUINE_DEBUG
			std::cout << "Time: " << m_Time->GetTimeInSeconds() << "s. Delta Time: " << m_Time->GetDeltaTime() << "s." << std::endl;
#endif

			Update(m_Time->GetDeltaTime());
		}
	}

	float Engine::Input()
	{
		Clock inputClock;

		if (m_Graphics->GetWindow()->pollEvent(*m_Event))
		{
			if (m_Event->type == sf::Event::KeyPressed)
			{
				// TODO: Call input manager
			}

			if (m_Event->type == sf::Event::Closed)
				m_Graphics->GetWindow()->close();
		}

		m_Graphics->GetWindow()->clear();
		
		return inputClock.getElapsedTime().asSeconds();
	}

	void Engine::Update(float deltaTimeInSeconds)
	{
		for (Scene* scene : m_Scenes)
		{
#if PENGUINE_DEBUG
			std::cout << "Scene: " << scene->GetName() << "; GameObjects: " << scene->GetGameObjectCount() << std::endl;
#endif
			for (GameObject go : scene->GetGameObjects())
			{
				if (&go == nullptr)
					continue;

#if PENGUINE_DEBUG
				std::cout << go.ToString() << std::endl;
#endif
			}
		}

		m_Graphics->GetWindow()->display();
	}
}