#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace penguine
{
	class Component;

	class TextBox: public Component
	{
	protected:
		sf::Vector2f* m_Offset;
		sf::Color m_FillColor;

		sf::Vector2u* m_Dimensions;
		sf::Font* m_Font;
		sf::Text* m_Text;
		std::string m_String;

		bool m_IsVisible = true;
		float m_StartTime = 0;
		float m_DisplayTime = .03f;

	public:
		TextBox();
		virtual ~TextBox();

		virtual void Update();
		virtual void Render();

		virtual void DoAction(std::string actionType);

		void SetString(std::string string);
		std::string GetString();

		void SetVisibility(bool isVisible);
		bool GetVisibility();

		void CheckTimer();

		void SetDisplayTime(float time);

		virtual std::string ToString();
		void SetFont(std::string path);

		friend class XMLTranslator;
	};
}