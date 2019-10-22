#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Scene.h"
#include "penguine/Graphics.h"
#include "penguine/Time.h"

using namespace sf;

namespace penguine
{
	class Engine
	{
	private:
		std::vector<Scene*> m_Scenes;
		Scene* m_CurrentScene;

		Graphics m_Graphics;

		Event m_Event;

		GameTime m_Time;

		void Input();
		void Update(float deltaTimeInSeconds);
		void Draw();

		void InitializeComponents();

		void GameLoop();

	public:
		Engine(Scene* startScene);
		~Engine();

		void Start();

		Engine* AddScene(Scene* scene);
		std::vector<Scene*> GetScenes();
	};
}