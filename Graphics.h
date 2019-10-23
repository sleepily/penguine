#pragma once
#include <SFML/Graphics.hpp>

typedef unsigned int	uint;

namespace penguine
{
	class Graphics
	{
	private:
		sf::RenderWindow* m_Window;

		sf::Vector2u m_Resolution;

		sf::Vector2u m_ResolutionDefault;

	public:
		Graphics();
		Graphics(sf::Vector2u resolution);
		~Graphics();

		sf::RenderWindow* GetWindow();
	};
}