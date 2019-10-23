#include <stdio.h>
#include <iostream>
#include "penguine/GameObject.h"
#include "penguine/Engine.h"
#include "penguine/SpriteRenderer.h"

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	// TODO: Replace this with XML reading
	penguine::Scene* scene = new penguine::Scene();

	penguine::GameObject* go = new penguine::GameObject();

	scene->AddGameObject(go);

	go->AddComponent(new penguine::SpriteRenderer());

	engine->AddScene(scene);

	engine->Start();

	return 0;
}