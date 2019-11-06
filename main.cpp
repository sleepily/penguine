#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/MoveToMouse.h"
#include "penguine/TextBox.h"
#include "penguine/Moveable.h"
#include "penguine/Transform.h"
#include "penguine/XML.h"
#include "rapidxml.hpp"

/*
TODO: move all header files to class factory
TODO: fix XML reading/writing
TODO: finish mouse input: buttons; relative position?
TODO: add keyboard input
*/

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	penguine::XML* xml = new penguine::XML("assets/data.xml");

	std::cout << xml->ToString() << std::endl;

	// TODO: Replace this with XML reading
	penguine::Scene* scene = new penguine::Scene();

	penguine::GameObject* go = new penguine::GameObject();

	scene->AddGameObject(go);

	/*
	penguine::TextBox* textBox = new penguine::TextBox();
	textBox->SetString("This is a test Text Box.");

	penguine::Moveable* moveable = new penguine::Moveable();
	moveable->movementType = penguine::Moveable::MovementType::ORBIT;
	moveable->amplitude = 1.0f;
	moveable->speed = 6.28f;
	*/

	penguine::SpriteRenderer* spriteRenderer = new penguine::SpriteRenderer();

	penguine::MoveToMouse* moveToMouse = new penguine::MoveToMouse();

	// go->AddComponent(textBox);
	// go->AddComponent(moveable);
	go->AddComponent(spriteRenderer);
	go->AddComponent(moveToMouse);
	
	engine->AddScene(scene);

	engine->Start();

	engine->~Engine();

	return 0;
}