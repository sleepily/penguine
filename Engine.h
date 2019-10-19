#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
private:
	RenderWindow m_Window;

	void input();
	void update(float deltaTime);
	void draw();

public:
	Engine();
	~Engine();

	void start();
};