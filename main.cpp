#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/TextBox.h"
#include "penguine/Moveable.h"
#include "penguine/Transform.h"

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

	penguine::Moveable* moveable = new penguine::Moveable();
	moveable->movementType = penguine::Moveable::MovementType::BOUNCE;
	moveable->amplitude = 1.0f;
	moveable->speed = 6.28f;

	go->AddComponent(moveable);

	go->GetTransform()->position = new sf::Vector3f(engine->GetGraphics()->GetWindow()->getSize().x / 3, engine->GetGraphics()->GetWindow()->getSize().y / 2, 0);

	engine->AddScene(scene);

	engine->Start();

	return 0;
}