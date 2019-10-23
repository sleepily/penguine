#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
typedef unsigned int	uint;

namespace penguine
{
	class Graphics
	{
	private:
		RenderWindow* m_Window;
		Time m_LastUpdate;

		Vector2u m_Resolution;

		Vector2u m_ResolutionDefault;

	public:
		Graphics();
		Graphics(uint x, uint y);
		~Graphics();

		RenderWindow* GetWindow();
	};
}