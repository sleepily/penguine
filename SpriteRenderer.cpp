#include <SFML/Graphics.hpp>
#include "penguine/SpriteRenderer.h"

using namespace sf;


namespace penguine
{
	SpriteRenderer::SpriteRenderer()
	{
		Texture* texture = new Texture();
		m_Sprite = new Sprite(*texture);
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Update()
	{

	}
	sf::Sprite* SpriteRenderer::GetSprite()
	{
		return m_Sprite;
	}
}
