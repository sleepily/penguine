#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace penguine
{
	class Component;

	class TextBox: public Component
	{
	protected:
		sf::Vector2i* m_Offset;
		sf::Color m_FillColor;

		sf::Vector2u* m_Dimensions;
		sf::Font* m_Font;
		sf::Text* m_Text;
		std::string m_String;

	public:
		TextBox();
		virtual ~TextBox();

		virtual void Update();
		virtual void Render();

		void SetString(std::string string);
		std::string GetString();

		virtual std::string ToString();
	};
}