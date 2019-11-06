#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

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

		virtual std::string ToString();

		void SetSprite(sf::Sprite* sprite);
		sf::Sprite* GetSprite();
	};
}