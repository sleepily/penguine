#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "MathX.h"
#include "Character.h"

namespace penguine
{
	class MoveToMouse: public Component
	{
	private:
		bool m_OnClick = true;
		sf::Vector3f *m_LerpStartPosition, *m_LerpEndPosition;
		float m_LerpDuration = 1.0f;
		float m_LastClick = 0;
		bool m_IsLerping = false;

		bool m_OnlyUseX = false;

	public:
		MoveToMouse();
		
		virtual void Update();
		virtual void Render();

		sf::Vector3f* GetMouseDirection();

		void Move();

		void OnClick();

		friend class Character;
	};
}