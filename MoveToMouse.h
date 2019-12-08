#pragma once
#include <SFML/Graphics.hpp>
#include "penguine/Component.h"
#include "penguine/MathX.h"

namespace penguine
{
	class MoveToMouse: public Component
	{
	private:
		bool m_OnClick = true;
		sf::Vector3f* m_LerpPosition;
		float m_LerpDuration = 1.0f;
		float m_LastClick = 0;
		bool m_IsLerping = false;

	public:
		MoveToMouse();
		
		virtual void Update();
		virtual void Render();

		void OnClick();
	};
}