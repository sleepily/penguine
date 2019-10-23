#include <SFML/Graphics.hpp>
#include "penguine/Graphics.h"

typedef unsigned int	uint;

namespace penguine
{
	Graphics::Graphics()
	{
		m_ResolutionDefault = Vector2u(400, 400);
		m_Window = new sf::RenderWindow();
		m_Window->create(sf::VideoMode(m_ResolutionDefault.x, m_ResolutionDefault.y), "penguine");
	}

	Graphics::Graphics(uint x, uint y)
	{
		m_Window = new sf::RenderWindow();
		m_Window->create(sf::VideoMode(x, y), "penguine");
	}

	Graphics::~Graphics()
	{
	
	}

	RenderWindow* Graphics::GetWindow()
	{
		return m_Window;
	}
}