#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Scene.h"
#include "penguine/Graphics.h"
#include "penguine/Time.h"

typedef unsigned int	uint;

namespace penguine
{
	class Engine
	{
	private:
		std::vector<Scene*> m_Scenes;

		Graphics* m_Graphics;

		sf::Event* m_Event;

		GameTime* m_Time;

		float m_TargetFPS;
		uint m_TargetInputPolls;

		float Input();
		void Update(float deltaTimeInSeconds);
		void Render();

		void GameLoop();

	public:
		Engine();
		Engine(Scene* startScene);
		~Engine();

		void Start();

		Graphics* GetGraphics();

		Engine* AddScene(Scene* scene);
		std::vector<Scene*> GetScenes();
	};
}