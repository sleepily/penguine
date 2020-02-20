#include "MoveToMouse.h"
#include "Character.h"

namespace penguine
{
	Character::Character()
	{
		m_Name = "Character";
		m_TextBox = new penguine::TextBox();
		m_MoveToMouse = new penguine::MoveToMouse();
		m_SpriteRenderer = new penguine::SpriteRenderer();

		AddComponent(m_TextBox);
		AddComponent(m_MoveToMouse);
		AddComponent(m_SpriteRenderer);
	}

	void Character::Start()
	{

	}

	void Character::Update()
	{
	}

	void Character::Move()
	{

	}

	void Character::SetInfo(std::string name, std::string dialogue)
	{
		m_CharacterName = name;
		m_Dialogue = dialogue;

		m_TextBox->SetString(m_Dialogue);
	}

	void Character::SetSprite(std::string path)
	{
		m_SpriteRenderer->SetSprite(path);
	}
}