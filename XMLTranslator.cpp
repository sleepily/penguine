#include <string>
#include "XMLTranslator.h"
#include "XML.h"
#include "XMLNode.h"
#include "Scene.h"
#include "PenguineObject.h"
#include "Component.h"
#include "Character.h"
#include "Dialogue.h"
#include "Sound.h"

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
		std::string sceneName = "", sceneID = "";
		
		if (nodeName != "scene")
			return NULL;

		if (XML::FindAttribute(node, "name"))
			sceneName = XML::FindAttribute(node, "name")->value();

		if (XML::FindAttribute(node, "id"))
			sceneID = XML::FindAttribute(node, "id")->value();

		int ID = (!sceneID.empty()) ? std::stoi(sceneID) : 0;

		Scene* scene = new Scene(ID, sceneName);

		scene->SetEngine(engine);

		for (rapidxml::xml_node<>* objectNode = node->first_node(); objectNode; objectNode = objectNode->next_sibling())
		{
			// Get GameObjects
			GameObject* objectInScene = ConvertToGameObject(objectNode);
			
			if (!objectInScene)
				continue;

			// Add Components
			for (rapidxml::xml_node<>* componentNode = objectNode->first_node(); componentNode; componentNode = componentNode->next_sibling())
			{
				Component* objectComponent = ConvertToComponent(componentNode);
				
				if (!objectComponent)
					continue;

				objectInScene->AddComponent(objectComponent);
			}

			scene->AddGameObject(objectInScene);
		}

		return scene;
	}

	GameObject* XMLTranslator::ConvertToGameObject(rapidxml::xml_node<>* node)
	{
		std::string nodeName = std::string(node->name());

		std::string objectType = "";

		if (nodeName == "component")
		{
			std::cout << "Please use the <component> node inside of an <object> node." << std::endl;
			return NULL;
		}

		if (XML::FindAttribute(node, "type"))
			objectType = XML::FindAttribute(node, "type")->value();

		if (objectType == "character")
		{
			Character* character = new Character();

			if (XML::FindAttribute(node, "name"))
				character->m_CharacterName = XML::FindAttribute(node, "name")->value();
			else
				std::cout << "Attribute \"name\" not found in character. Keeping Default." << std::endl;
		    
			if (XML::FindAttribute(node, "sprite"))
				character->SetSprite(XML::FindAttribute(node, "sprite")->value());
			else
				std::cout << "Attribute \"sprite\" not found in character. Keeping Default." << std::endl;

			if (XML::FindAttribute(node, "action"))
				character->m_SpriteRenderer->SetActionType(XML::FindAttribute(node, "action")->value());

			if (XML::FindAttribute(node, "x"))
				character->GetTransform()->position->x = std::stoi(XML::FindAttribute(node, "x")->value());
			if (XML::FindAttribute(node, "y"))
				character->GetTransform()->position->y = std::stoi(XML::FindAttribute(node, "y")->value());

			return character;
		}

		if (objectType == "image")
		{
			GameObject* image = new GameObject();

			SpriteRenderer* spriteRenderer = new SpriteRenderer();

			if (XML::FindAttribute(node, "sprite"))
				spriteRenderer->SetSprite(XML::FindAttribute(node, "sprite")->value());

			if (XML::FindAttribute(node, "action"))
				spriteRenderer->SetActionType(XML::FindAttribute(node, "action")->value());
			
			image->AddComponent(spriteRenderer);

			if (XML::FindAttribute(node, "x"))
				image->GetTransform()->position->x = std::stoi(XML::FindAttribute(node, "x")->value());
			if (XML::FindAttribute(node, "y"))
				image->GetTransform()->position->y = std::stoi(XML::FindAttribute(node, "y")->value());
			
			return image;
		}

		return new GameObject();
	}

	Component* XMLTranslator::ConvertToComponent(rapidxml::xml_node<>* node)
	{
		std::string nodeName = std::string(node->name());

		std::string objectType = "";

		if (XML::FindAttribute(node, "type"))
			objectType = XML::FindAttribute(node, "type")->value();

		if (objectType == "text")
		{
			TextBox* text = new TextBox();
			
			text->SetString(node->value());

			if (XML::FindAttribute(node, "action"))
			{
				text->SetActionType(XML::FindAttribute(node, "action")->value());
				text->SetVisibility(false); // Hide text if it has to be activated through an action
			}

			if (XML::FindAttribute(node, "time"))
				text->SetDisplayTime(std::stof(XML::FindAttribute(node, "time")->value()));

			if (XML::FindAttribute(node, "size"))
				text->m_Text->setCharacterSize(std::stoi(XML::FindAttribute(node, "size")->value()));

			if (XML::FindAttribute(node, "font"))
				text->SetFont(XML::FindAttribute(node, "font")->value());

			return text;
		}

		if (objectType == "sound")
		{
			Sound* sound = new Sound();

			if (XML::FindAttribute(node, "file"))
				sound->LoadFromFile(XML::FindAttribute(node, "file")->value());

			if (XML::FindAttribute(node, "volume"))
				sound->m_Sound->setVolume(std::stoi(XML::FindAttribute(node, "volume")->value()));

			if (XML::FindAttribute(node, "loop"))
			{
				std::string loopValue = XML::FindAttribute(node, "loop")->value();

				if (loopValue == "yes" || loopValue == "true")
					sound->m_IsLoop = true;
			}

			if (XML::FindAttribute(node, "autoplay"))
			{
				std::string autoplayValue = XML::FindAttribute(node, "autoplay")->value();

				if (autoplayValue == "yes" || autoplayValue == "true")
					sound->m_IsAutoplay = true;
			}

			if (XML::FindAttribute(node, "action"))
			{
				sound->m_ActionType = XML::FindAttribute(node, "action")->value();
				// turn autoplay off
			}

			return sound;
		}

		return NULL;
	}
}
