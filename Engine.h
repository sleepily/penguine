#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "XML.h"

typedef unsigned int	uint;

namespace penguine
{
	class Input;

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
		void ReadObjects(XML* xml);

		Graphics* GetGraphics();
		penguine::GameTime* GetTime();
		penguine::Input* GetInput();

		Engine* AddScene(Scene* scene);
		std::vector<Scene*> GetScenes();
	};
}