#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/TextBox.h"
#include "penguine/Moveable.h"
#include "penguine/Transform.h"
#include "rapidxml.hpp"

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	// TODO: Replace this with XML reading
	penguine::Scene* scene = new penguine::Scene();

	penguine::GameObject* go = new penguine::GameObject();

	scene->AddGameObject(go);

	penguine::TextBox* textBox = new penguine::TextBox();
	textBox->SetString("This is a test Text Box.");

	penguine::Moveable* moveable = new penguine::Moveable();
	moveable->movementType = penguine::Moveable::MovementType::ORBIT;
	moveable->amplitude = 1.0f;
	moveable->speed = 6.28f;

	penguine::SpriteRenderer* spriteRenderer = new penguine::SpriteRenderer();

	// go->AddComponent(textBox);
	go->AddComponent(moveable);
	go->AddComponent(spriteRenderer);

	go->GetTransform()->position = new sf::Vector3f(engine->GetGraphics()->GetWindow()->getSize().x / 3.0f, engine->GetGraphics()->GetWindow()->getSize().y / 2.0f, 0);

	engine->AddScene(scene);

	engine->Start();

	return 0;
}