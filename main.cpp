#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/TextBox.h"

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	// TODO: Replace this with XML reading
	penguine::Scene* scene = new penguine::Scene();

	penguine::GameObject* go = new penguine::GameObject();

	scene->AddGameObject(go);

	// go->AddComponent(new penguine::SpriteRenderer());

	penguine::TextBox* textBox = new penguine::TextBox();
	textBox->SetString("This is a test Text Box.");
	go->AddComponent(textBox);

	go->GetTransform()->position = new sf::Vector3f(30, 30, 0);

	engine->AddScene(scene);

	engine->Start();

	return 0;
}