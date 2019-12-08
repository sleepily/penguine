#include "BoxCollider.h"

namespace penguine
{
	BoxCollider::BoxCollider(GameObject* go)
	{
		m_GameObject = go;
		SetEngine(go->engine);

		Rectangle = new sf::IntRect(0, 0, 100, 100);

		SpriteRenderer* spriteRenderer = new SpriteRenderer();
		m_GameObject->AddComponent(spriteRenderer);

		sf::IntRect textureRect = spriteRenderer->GetSprite()->getTextureRect();
		sf::Vector2f spriteScale = spriteRenderer->GetSprite()->getScale();
		this->Rectangle = new sf::IntRect(textureRect);
	}

	BoxCollider::BoxCollider(SpriteRenderer* spriteRenderer)
	{
		Rectangle = new sf::IntRect(0, 0, 100, 100);

		sf::IntRect textureRect = spriteRenderer->GetSprite()->getTextureRect();
		sf::Vector2f spriteScale = spriteRenderer->GetSprite()->getScale();
		this->Rectangle = new sf::IntRect(textureRect);
	}

	BoxCollider::BoxCollider(sf::Sprite* sprite)
	{
		Rectangle = new sf::IntRect(0, 0, 100, 100);

		sf::IntRect textureRect = sprite->getTextureRect();
		sf::Vector2f spriteScale = sprite->getScale();
		this->Rectangle = new sf::IntRect(textureRect);
	}

	BoxCollider::~BoxCollider()
	{
	}

	void BoxCollider::Update()
	{
		if (!m_IsEnabled)
			return;

		sf::Vector2f pos = *m_GameObject->GetTransform()->position2D();
		this->Rectangle->left = (int)pos.x;
		this->Rectangle->top = (int)pos.y;
	}

	void BoxCollider::Render()
	{
		if (!m_IsEnabled)
			return;

		if (!isVisible)
			return;

		RenderRectangle();
	}

	void BoxCollider::RenderRectangle()
	{
		sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(Rectangle->width, Rectangle->height));

		rect->setPosition(*m_GameObject->GetTransform()->position2D());
		rect->setOutlineThickness(1);
		rect->setFillColor(sf::Color::Transparent);
		rect->setOutlineColor(sf::Color::Green);

		engine->GetGraphics()->GetWindow()->draw(*rect);
	}

	void BoxCollider::SetVisibility(bool isVisible)
	{
		this->isVisible = isVisible;
	}

	std::string BoxCollider::ToString()
	{
		return std::string();
	}
}
