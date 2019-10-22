#include <SFML/Graphics.hpp>
#include "penguine/Graphics.h"

namespace penguine
{
	Graphics::Graphics()
	{
		m_Window = new sf::RenderWindow();
		m_Window->create(sf::VideoMode(600, 800), "penguine");
	}

	Graphics::~Graphics()
	{
	
	}

	RenderWindow* Graphics::GetWindow()
	{
		return m_Window;
	}
}