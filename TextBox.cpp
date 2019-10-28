#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "penguine/Engine.h"

namespace penguine
{
	TextBox::TextBox()
	{
		m_Dimensions = new sf::Vector2u(100, 100);
		m_Font = new sf::Font();
		m_Font->loadFromFile("assets/fonts/Squared Display.ttf");
		m_String = "";

		m_Text = new sf::Text();
	}

	TextBox::~TextBox()
	{
	}

	void TextBox::Update()
	{
		m_Text->setFont(*m_Font);
		std::cout << m_GameObject->GetTransform()->position2D()->x << "x, " << m_GameObject->GetTransform()->position2D()->y << "y." << std::endl;
		m_Text->setPosition(*m_GameObject->GetTransform()->position2D());
		m_Text->setCharacterSize(26);
		// m_Text->setColor(sf::Color(0, 255, 0));
		m_Text->setFillColor(sf::Color(0, 255, 0));
		m_Text->setOutlineThickness(2.0f);

		m_Text->setString(m_String);
	}

	void TextBox::Render()
	{
		engine->GetGraphics()->GetWindow()->draw(*m_Text);
	}
	void TextBox::SetString(std::string string)
	{
		m_String = string;
	}
	std::string TextBox::GetString()
	{
		return m_String;
	}
}