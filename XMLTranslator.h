#pragma once
#include <list>
#include "XML.h"
#include "Scene.h"
#include "PenguineObject.h"
#include "Component.h"

namespace penguine
{
	class XMLTranslator
	{
	private:
		std::vector<Scene*>* m_Scenes;

	public:
		std::vector<Scene*>* TranslateXML(XML* xml, Engine* engine);
		Scene* ConvertToScene(rapidxml::xml_node<>* node, Engine* engine);
		GameObject* ConvertToGameObject(rapidxml::xml_node<>* node);
	};
}