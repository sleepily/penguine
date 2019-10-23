#include <SFML/Graphics.hpp>
#include "penguine/Graphics.h"

typedef unsigned int	uint;

namespace penguine
{
	Graphics::Graphics()
	{
		m_ResolutionDefault = sf::Vector2u(400, 400);
		Graphics(m_ResolutionDefault);
	}

	Graphics::Graphics(sf::Vector2u resolution)
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(resolution.x, resolution.y), "penguine");
	}

	Graphics::~Graphics()
	{
	
	}

	sf::RenderWindow* Graphics::GetWindow()
	{
		return m_Window;
	}
}