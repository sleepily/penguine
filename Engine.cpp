#include <iostream>
#include <string>
#include <list>
#include "SystemSettings.h"
#include "Engine.h"
#include "XMLTranslator.h"

namespace penguine
{
	Engine::Engine()
	{
		m_Event = new sf::Event();
		m_Time = new penguine::GameTime();
		m_Input = new penguine::Input();

		m_Graphics = new Graphics(sf::Vector2u(800, 600));
	}
	Engine::Engine(Scene* startScene)
	{
		Engine();
		AddScene(startScene);
	}

	Engine::~Engine()
	{
#ifdef PENGUINE_DEBUG
		std::cout << std::endl;
		std::cout << "Shutting down..." << std::endl;
		std::cout << "Calling destructors..." << std::endl;
#endif // PENGUINE_DEBUG

		for (Scene* scene : m_Scenes)
		{
#ifdef PENGUINE_DEBUG
			std::cout << std::endl;
			std::cout << "Scene " << scene->GetName() << ": " << std::endl;
			std::cout << scene->ToString() << std::endl;
#endif // PENGUINE_DEBUG

			for (GameObject* go : *scene->GetGameObjects())
			{
				for (Component* component : *go->GetComponents())
					component->~Component();

				go->~GameObject();
			}

			scene->~Scene();
		}

#ifdef PENGUINE_DEBUG
		std::cout << "Finished shutting down." << std::endl;
#endif // PENGUINE_DEBUG
	}

	void Engine::Start()
	{
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

	Input* Engine::GetInput()
	{
		return m_Input;
	}

	Engine* Engine::AddScene(Scene* scene)
	{
#if PENGUINE_DEBUG
		std::cout << "Adding Scene " << scene->GetName() << "..." << std::endl;
#endif // PENGUINE_DEBUG
		scene->SetEngine(this);

		m_Scenes.push_back(scene);
		
		return this;
	}

	std::vector<Scene*> Engine::GetScenes()
	{
		return m_Scenes;
	}

	void Engine::ReadObjects(XML* xml)
	{
		XMLTranslator* translator = new XMLTranslator();

		std::vector<Scene*>* scenesToAdd = translator->TranslateXML(xml, this);

		for (Scene* sceneToAdd : *scenesToAdd)
			AddScene(sceneToAdd);
	}
	
	void Engine::GameLoop()
	{
		uint updates = 0;

#ifdef PENGUINE_DEBUG
		std::cout << "Target FPS: " << system::TARGET_FPS << std::endl;
		std::cout << "Starting Game Loop." << std::endl << std::endl;
#endif // PENGUINE_DEBUG

		while (m_Graphics->GetWindow()->isOpen())
		{
			m_Time->ResetClock();

			// Prevent rendering too fast using target FPS
			float fpsDelay = 1.0f / system::TARGET_FPS;

			float timeUntilNextRender = (m_Time->GetLastUpdate().asSeconds() + fpsDelay) - m_Time->GetTimeInSeconds();

			if (timeUntilNextRender > 0.0f)
			{
				updates++;

#ifdef PENGUINE_DEBUG
				std::cout << "Time until next Update: " << timeUntilNextRender << " s" << std::endl;
#endif

				sf::sleep(sf::microseconds((int)(fpsDelay / 10.0f * 1000000.0f)));
				continue;
			}

#if PENGUINE_DEBUG
			float deltaTime = m_Time->GetDeltaTime();
			float fps = 1.0f / deltaTime;

			std::cout << std::endl << "Time: " << m_Time->GetTimeInSeconds() << " s" << std::endl;
			std::cout << "Delta Time: " << deltaTime << " s" << std::endl;
			std::cout << "FPS: " << fps << std::endl;
			std::cout << "Updates: " << system::TARGET_UPDATES << std::endl << std::endl;
#endif

			updates = 0;

			Input();
			Update();
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
			if (m_Event->type == sf::Event::Closed)
				m_Graphics->GetWindow()->close();

			m_Input->PollFromEvent(*m_Event);
		}

#ifdef PENGUINE_DEBUG
		std::cout << "Finished Input Poll." << std::endl;
#endif

		return inputClock.getElapsedTime().asSeconds();
	}

	void Engine::Update()
	{
		m_Input->Update();

		m_Time->Update();

		for (Scene* scene : m_Scenes)
			scene->Update();

#if PENGUINE_DEBUG
		std::cout << "Finished Update." << std::endl << std::endl;
#endif
	}

	void Engine::Render()
	{
		m_Graphics->GetWindow()->clear();

		for (Scene* scene : m_Scenes)
			scene->Render();

#if PENGUINE_DEBUG
		std::cout << "Finished Render." << std::endl << std::endl;
#endif

		m_Graphics->GetWindow()->display();
	}
}