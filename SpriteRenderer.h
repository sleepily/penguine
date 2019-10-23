#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"

namespace penguine
{
	class Component;

	class SpriteRenderer : public Component
	{
	protected:
		sf::Sprite* m_Sprite;

	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Update();
		virtual void Render();

		void SetSprite(sf::Sprite* sprite);
		sf::Sprite* GetSprite();
	};
}