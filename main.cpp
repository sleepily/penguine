#include <stdio.h>
#include <iostream>
#include "GameObject.h"
#include "Engine.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"
#include "MoveToMouse.h"
#include "TextBox.h"
#include "Moveable.h"
#include "Transform.h"
#include "Character.h"
#include "XML.h"

/*
TODO: move all header files to class factory
TODO: fix XML reading/writing, XML ToString()
TODO: add keyboard input
*/

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	penguine::XML* xml = new penguine::XML("assets/data.xml");

	engine->ReadObjects(xml);

	/*
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

	penguine::BoxCollider* boxCollider = new penguine::BoxCollider(spriteRenderer);
	boxCollider->SetVisibility(true);

	penguine::MoveToMouse* moveToMouse = new penguine::MoveToMouse();
	

	// go->AddComponent(textBox);
	// go->AddComponent(moveable);
	// go->AddComponent(spriteRenderer);
	// go->AddComponent(boxCollider);
	// go->AddComponent(moveToMouse);
	
	engine->AddScene(scene);
	*/

	engine->Start();

	engine->~Engine();

	return 0;
}