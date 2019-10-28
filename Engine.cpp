#include <iostream>
#include <string>
#include "penguine/SystemSettings.h"
#include "penguine/Engine.h"

namespace penguine
{
	Engine::Engine()
	{
		m_Event = new sf::Event();
		m_Time = new GameTime();

		m_Graphics = new Graphics(sf::Vector2u(800, 600));
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
			scene->SetEngine(this);;

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

	GameTime* Engine::GetTime()
	{
		return m_Time;
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
		uint updates = 0;

		std::cout << system::TARGET_FPS << std::endl;

		while (m_Graphics->GetWindow()->isOpen())
		{
			m_Time->ResetClock();

			Input();

			// Prevent rendering too fast using target FPS
			float fpsDelay = 1.0f / system::TARGET_FPS;

			float timeUntilNextRender = (m_Time->GetLastUpdate().asSeconds() + fpsDelay) - m_Time->GetTimeInSeconds();

			if (timeUntilNextRender > 0.0f)
			{
				updates++;
				std::cout << "Time until next render: " << timeUntilNextRender << " s" << std::endl;
				sf::sleep(sf::microseconds((int)(fpsDelay / 10 * 1000000.0f)));
				continue;
			}

#if PENGUINE_DEBUG
			float fps = 1.0f / m_Time->GetDeltaTime();

			std::cout << std::endl << "Time: " << m_Time->GetTimeInSeconds() << " s" << std::endl;
			std::cout << "Delta Time: " << m_Time->GetDeltaTime() << " s" << std::endl;
			std::cout << "FPS: " << fps << std::endl;
			std::cout << "Updates: " << system::TARGET_UPDATES << std::endl << std::endl;
#endif

			updates = 0;

			Update(m_Time->GetDeltaTime());
			Render();
		}
	}

	float Engine::Input()
	{
		sf::Clock inputClock;

#ifdef PENGUINE_DEBUG
		std::cout << "Starting Input Poll..." << std::endl;
#endif

		m_Event = new sf::Event();

		while (m_Graphics->GetWindow()->pollEvent(*m_Event))
		{
			// TODO: add Input class

			if (m_Event->type == sf::Event::Closed)
				m_Graphics->GetWindow()->close();
		}

#ifdef PENGUINE_DEBUG
		std::cout << "Finished Input Poll." << std::endl;
#endif

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
#if PENGUINE_DEBUG
		std::cout << "Rendering " << scene->ToString() << "..." << std::endl;
#endif
			scene->Render();

#if PENGUINE_DEBUG
		std::cout << "Finished Rendering " << scene->ToString() << "." << std::endl;
#endif
		}

#if PENGUINE_DEBUG
		std::cout << "Finished Render." << std::endl << std::endl;
#endif

		m_Graphics->GetWindow()->display();
	}
}