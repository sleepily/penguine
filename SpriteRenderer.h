#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

namespace penguine
{
	class SpriteRenderer : public Component
	{
	protected:
		sf::Sprite* m_Sprite;

	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Update();
		virtual void Render();

		sf::Sprite* GetSprite();
	};
}