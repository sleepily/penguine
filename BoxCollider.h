#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "SpriteRenderer.h"
#include "Engine.h"

namespace penguine
{
	class Component;
	class SpriteRenderer;

	class BoxCollider : public Component
	{
	private:
		sf::IntRect* Rectangle;
		SpriteRenderer* spriteRenderer;
		bool isVisible = false;
		void RenderRectangle();

	public:
		BoxCollider(GameObject* go);
		BoxCollider(SpriteRenderer* spriteRenderer);
		BoxCollider(sf::Sprite* sprite);
		virtual ~BoxCollider();

		virtual void Update();
		virtual void Render();

		void SetVisibility(bool isVisible);

		virtual std::string ToString();
	};
}
