#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace penguine
{
	class Graphics
	{
	private:
		RenderWindow* m_Window;
		Time m_LastUpdate;

		Vector2i m_Resolution;

	public:
		Graphics();
		~Graphics();

		RenderWindow* GetWindow();
	};
}