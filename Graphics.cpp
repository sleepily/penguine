#include <SFML/Graphics.hpp>
#include "penguine/Graphics.h"

typedef unsigned int	uint;

namespace penguine
{
	Graphics::Graphics()
	{
		m_ResolutionDefault = Vector2u(400, 400);
		Graphics(m_ResolutionDefault.x, m_ResolutionDefault.y);
	}

	Graphics::Graphics(uint x, uint y)
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(x, y), "penguine");
	}

	Graphics::~Graphics()
	{
	
	}

	RenderWindow* Graphics::GetWindow()
	{
		return m_Window;
	}
}