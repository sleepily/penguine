#include <iostream>
#include <string>
#include "penguine/Engine.h"

namespace penguine
{
	Engine::Engine()
	{
		m_TargetFPS = 60.0f;
		m_TargetInputPolls = 10;

		m_Event = new sf::Event();
		m_Time = new GameTime();

		m_Graphics = new Graphics(sf::Vector2u(400, 400));
	}
	Engine::Engine(Scene* startScene)
	{
		Engine();
		AddScene(startScene);

#if PENGUINE_DEBUG
		std::cout << "\tStarting Penguine with scene " << startScene->GetName() << std::endl << std::endl;
#endif
	}

	Engine::~Engine()
	{

	}

	void Engine::Start()
	{
		for (Scene* scene : m_Scenes)
			scene->engine = this;

		if (m_Scenes.size() == 0)
		{
			std::cout << "No scene loaded! Please add Scenes using engine->AddScene(). Aborting..." << std::endl;
			return;
		}

		GameLoop();
	}

	Graphics* Engine::GetGraphics()
	{
		return m_Graphics;
	}

	Engine* Engine::AddScene(Scene* scene)
	{
		scene->SetEngine(this);

		m_Scenes.push_back(scene);
		
		return this;
	}

	std::vector<Scene*> Engine::GetScenes()
	{
		return m_Scenes;
	}
	
	void Engine::GameLoop()
	{
		uint inputPolls = 0;

		while (m_Graphics->GetWindow()->isOpen())
		{
			m_Time->ResetClock();

			Input();

			// Prevent rendering too fast using target FPS
			float fpsDelay = 1.0f / m_TargetFPS;

			if (m_Time->GetTimeInSeconds() < m_Time->GetLastUpdate().asSeconds() + fpsDelay)
			{
				sf::sleep(sf::microseconds((int)(fpsDelay / m_TargetInputPolls * 1000000.0f)));
				inputPolls++;
				continue;
			}

			float fps = 1.0f / m_Time->GetDeltaTime();
#if PENGUINE_DEBUG
			std::cout << std::endl << "Time: " << m_Time->GetTimeInSeconds() << " s" << std::endl;
			std::cout << "Delta Time: " << m_Time->GetDeltaTime() << " s" << std::endl;
			std::cout << "FPS: " << fps << std::endl;
			std::cout << "Input Polls: " << inputPolls << std::endl << std::endl;
#endif

			inputPolls = 0;

			Update(m_Time->GetDeltaTime());
			Render();
		}
	}

	float Engine::Input()
	{
		sf::Clock inputClock;

		m_Event = new sf::Event();

		while (m_Graphics->GetWindow()->pollEvent(*m_Event))
		{
			// TODO: add Input class

			if (m_Event->type == sf::Event::Closed)
				m_Graphics->GetWindow()->close();
		}

		return inputClock.getElapsedTime().asSeconds();
	}

	void Engine::Update(float deltaTimeInSeconds)
	{
		m_Time->Update();

		for (Scene* scene : m_Scenes)
		{
#if PENGUINE_DEBUG
			std::cout << scene->ToString() << std::endl;
#endif
			scene->Update();
		}
	}

	void Engine::Render()
	{
		m_Graphics->GetWindow()->clear();

		for (Scene* scene : m_Scenes)
		{
			scene->Render();
		}

		m_Graphics->GetWindow()->display();
	}
}