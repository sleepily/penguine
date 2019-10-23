#include <SFML/Graphics.hpp>
#include <iostream>
#include "penguine/Component.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/Engine.h"

namespace penguine
{
	SpriteRenderer::SpriteRenderer()
	{
#if PENGUINE_DEBUG
		std::cout << "Initializing SpriteRenderer..." << std::endl;
#endif
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("assets/snake1.png");
		m_Sprite = new sf::Sprite(*texture);
		m_Name = "SpriteRenderer";
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Update()
	{
		sf::Vector3f* goPosition = m_GameObject->GetTransform()->position;
		sf::Vector2f spritePosition(goPosition->x, goPosition->y);
		// TODO: Set Sprite origin to half width and half height
		m_Sprite->setPosition(spritePosition);
	}

	void SpriteRenderer::Render()
	{
		engine->GetGraphics()->GetWindow()->draw(*m_Sprite);
	}

	void SpriteRenderer::SetSprite(sf::Sprite* sprite)
	{
		m_Sprite = sprite;
	}

	sf::Sprite* SpriteRenderer::GetSprite()
	{
		return m_Sprite;
	}
}
