#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

using namespace sf;

namespace penguine
{
	class SpriteRenderer : public Component
	{
	protected:
		Sprite* m_Sprite;

	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Update();

		sf::Sprite* GetSprite();
	};
}