#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Engine.h"

namespace penguine
{
	TextBox::TextBox()
	{
		m_Dimensions = new sf::Vector2u(100, 100);
		m_Font = new sf::Font();
		m_Font->loadFromFile("assets1/fonts/DEADCRT.ttf");
		m_String = "";
		m_IsEnabled = true;

		m_Name = "TextBox";

		m_Text = new sf::Text();
	}

	TextBox::~TextBox()
	{
	}

	void TextBox::Update()
	{
		if (!m_IsEnabled)
			return;

		m_Text->setFont(*m_Font);

		m_Text->setPosition(*m_GameObject->GetTransform()->position2D());
		m_Text->setCharacterSize(18);
		m_Text->setFillColor(sf::Color(0, 255, 0));
		m_Text->setOutlineThickness(1.0f);
		m_Text->setOutlineColor(sf::Color::Red);

		m_Text->setString(m_String);

#ifdef PENGUINE_DEBUG
		std::cout << "Updated " << m_Name << "..." << std::endl;
#endif // PENGUINE_DEBUG
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

		// m_Text->setOrigin(m_GameObject->GetTransform()->position->x, m_GameObject->GetTransform()->position->y);
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