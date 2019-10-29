#include <SFML/Graphics.hpp>
#include <iostream>
#include "penguine/Component.h"
#include "penguine/SpriteRenderer.h"
#include "penguine/Engine.h"

namespace penguine
{
	SpriteRenderer::SpriteRenderer()
	{
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("assets1/snake1.png");
		m_Sprite = new sf::Sprite(*texture);
		m_Name = "SpriteRenderer";
		m_IsEnabled = true;
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Update()
	{
		if (!m_IsEnabled)
			return;

		sf::Vector3f* goPosition = m_GameObject->GetTransform()->position;
		sf::Vector2f spritePosition(goPosition->x, goPosition->y);
		// TODO: Set Sprite origin to half width and half height
		// sf::Vector2f half = sf::Vector2f(m_Sprite->getLocalBounds().width / 2.0f, m_Sprite->getLocalBounds().height / 2.0f);
		m_Sprite->setPosition(spritePosition);

#ifdef PENGUINE_DEBUG
		std::cout << "Updated " << ToString() << "..." << std::endl;
#endif // PENGUINE_DEBUG
	}

	void SpriteRenderer::Render()
	{
		if (!m_IsEnabled)
			return;

		engine->GetGraphics()->GetWindow()->draw(*m_Sprite);

#ifdef PENGUINE_DEBUG
		std::cout << "Rendered " << ToString() << "..." << std::endl;
#endif // PENGUINE_DEBUG
	}

	std::string SpriteRenderer::ToString()
	{
		return m_Name;
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
