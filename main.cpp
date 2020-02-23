#include <stdio.h>
#include <iostream>
#include "Engine.h"
#include "XML.h"

int main()
{
	penguine::Engine* engine = new penguine::Engine();

	penguine::XML* xml = new penguine::XML("assets/data.xml");

	engine->ReadObjects(xml);

	engine->Start();

	engine->~Engine();

	return 0;
}