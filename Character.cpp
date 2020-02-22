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
		m_SpriteRenderer->SetSprite("assets/char.png");

		m_TargetPosition = new sf::Vector3f();

		AddComponent(m_TextBox);
		AddComponent(m_MoveToMouse);
		AddComponent(m_SpriteRenderer);
	}

	void Character::Start()
	{

	}

	void Character::Update()
	{
		for (Component* component : *m_Components)
			component->Update();
	}

	void Character::SetDialogue(std::string dialogue)
	{
		m_Dialogue = dialogue;
		m_TextBox->SetString(m_Dialogue);
	}

	void Character::SetSprite(std::string path)
	{
		m_SpriteRenderer->SetSprite(path);
	}
}