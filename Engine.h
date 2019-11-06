#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Scene.h"
#include "penguine/Graphics.h"
#include "penguine/Input.h"
#include "penguine/Time.h"

typedef unsigned int	uint;

namespace penguine
{
	class Engine
	{
	private:
		std::vector<Scene*> m_Scenes;

		Graphics* m_Graphics;
		penguine::Input* m_Input;
		penguine::GameTime* m_Time;

		sf::Event* m_Event;

		float Input();
		void Update();
		void Render();

		void GameLoop();

	public:
		Engine();
		Engine(Scene* startScene);
		~Engine();

		void Start();

		Graphics* GetGraphics();
		penguine::GameTime* GetTime();
		penguine::Input* GetInput();

		Engine* AddScene(Scene* scene);
		std::vector<Scene*> GetScenes();
	};
}