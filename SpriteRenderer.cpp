#include <SFML/Graphics.hpp>
#include "penguine/SpriteRenderer.h"

using namespace sf;


namespace penguine
{
	SpriteRenderer::SpriteRenderer()
	{
		Texture* texture = new Texture();
		this->m_Sprite = Sprite(*texture);
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Update()
	{

	}
}
