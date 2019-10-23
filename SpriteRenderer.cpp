#include <SFML/Graphics.hpp>
#include "penguine/SpriteRenderer.h"
#include <iostream>

namespace penguine
{
	SpriteRenderer::SpriteRenderer()
	{
#if PENGUINE_DEBUG
		std::cout << "Initializing SpriteRenderer..." << std::endl;
#endif
		sf::Texture* texture = new sf::Texture();
		m_Sprite = new sf::Sprite(*texture);
		m_Name = "SpriteRenderer";
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::Render()
	{
	}

	sf::Sprite* SpriteRenderer::GetSprite()
	{
		return m_Sprite;
	}
}
