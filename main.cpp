#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"

using namespace penguine;

int main()
{
	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(80.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	*/

	/*
	penguine::GameObject go;
	go.AddComponent(new Component());
	std::cout << go.ToString() << std::endl;
	*/

	penguine::Scene* scene = new penguine::Scene();

	penguine::GameObject* go = new penguine::GameObject();

	scene->AddGameObject(go);

	penguine::Engine engine(scene);

	engine.Start();

	return 0;
}