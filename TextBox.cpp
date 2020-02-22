#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include "TextBox.h"
#include "Engine.h"

namespace penguine
{
	TextBox::TextBox()
	{
		m_Dimensions = new sf::Vector2u(100, 100);
		m_Font = new sf::Font();
		m_Font->loadFromFile("assets/Believer.otf");
		m_String = "";
		m_IsEnabled = true;

		m_Offset = new sf::Vector2f(0.0f, -40.0f);

		m_Name = "TextBox";

		m_Text = new sf::Text();

		m_Text->setCharacterSize(30);
		m_Text->setFillColor(sf::Color::White);
	}

	TextBox::~TextBox()
	{
	}

	void TextBox::Update()
	{
		if (!m_IsEnabled)
			return;

		m_Text->setFont(*m_Font);

		m_Text->setPosition(*m_GameObject->GetTransform()->position2D() + *m_Offset);

		m_Text->setString(m_String);
	}

	void TextBox::Render()
	{
		if (!m_IsEnabled)
			return;

		engine->GetGraphics()->GetWindow()->draw(*m_Text);
	}
	
	void TextBox::SetString(std::string string)
	{
		m_String = string;

		sf::FloatRect textRect = m_Text->getLocalBounds();
		m_Text->setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
	}
	
	std::string TextBox::GetString()
	{
		return m_String;
	}

	std::string TextBox::ToString()
	{
		return m_Name;
	}
}