#include <string>
#include "XMLTranslator.h"
#include "XML.h"
#include "XMLNode.h"
#include "Scene.h"
#include "PenguineObject.h"
#include "Component.h"
#include "Character.h"

namespace penguine
{
	std::vector<Scene*>* XMLTranslator::TranslateXML(XML* xml, Engine* engine)
	{
		m_Scenes = new std::vector<Scene*>();

		for (rapidxml::xml_node<>* child = xml->GetRootNode()->first_node(); child; child = child->next_sibling())
			m_Scenes->push_back(ConvertToScene(child, engine));

		return m_Scenes;
	}

	Scene* XMLTranslator::ConvertToScene(rapidxml::xml_node<>* node, Engine* engine)
	{
		std::string nodeName = std::string(node->name());

		// const rapidxml::node_type nodeType = node->type();
		
		if (nodeName != "scene")
			return NULL;

		std::string sceneName(XML::FindAttribute(node, "name")->value());

		std::string sID(XML::FindAttribute(node, "id")->value());
		int sceneID = std::stoi(sID);

		Scene* scene = new Scene(sceneID, sceneName);

		scene->SetEngine(engine);

		for (rapidxml::xml_node<>* childNode = node->first_node(); childNode; childNode = childNode->next_sibling())
			scene->AddGameObject(ConvertToGameObject(childNode));

		return scene;
	}

	GameObject* XMLTranslator::ConvertToGameObject(rapidxml::xml_node<>* node)
	{
		std::string nodeName = std::string(node->name());
		std::string nodeValue = std::string(node->value());

		if (nodeName == "character")
		{
			Character* character = new Character();

			if (XML::FindAttribute(node, "name"))
				character->m_CharacterName = XML::FindAttribute(node, "name")->value();
			else
				std::cout << "Attribute \"name\" not found in character. Keeping Default." << std::endl;

			if (XML::FindChildNode(node, "dialogue"))
				character->SetDialogue(XML::FindChildNode(node, "dialogue")->value());
			else
				std::cout << "Child node <dialogue> not found in character." << std::endl;

			if (XML::FindAttribute(node, "sprite"))
				character->SetSprite(XML::FindAttribute(node, "sprite")->value());
			else
				std::cout << "Attribute \"sprite\" not found in character. Keeping Default." << std::endl;

			return character;
		}
	}
}
