#pragma once
#include "MoveToMouse.h"
#include "TextBox.h"
#include "SpriteRenderer.h"

namespace penguine
{
	class Character : public GameObject
	{
	private:
		std::string m_CharacterName;
		std::string m_Dialogue;

		sf::Vector3f* m_TargetPosition;

		TextBox* m_TextBox;
		MoveToMouse* m_MoveToMouse;
		SpriteRenderer* m_SpriteRenderer;

	public:
		Character();

		virtual void Start();
		virtual void Update();

		void SetDialogue(std::string dialogue);
		void SetSprite(std::string path);

		friend class XMLTranslator;
	};
}