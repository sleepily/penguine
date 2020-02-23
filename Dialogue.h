#pragma once
#include "Component.h"
#include "TextBox.h"
#include "XMLTranslator.h"
#include "Engine.h"

namespace penguine
{
	class Dialogue : public Component
	{
	private:
		TextBox* m_TextBox;

		float m_StartTime = 0;

		float m_DisplayTime = 3.0f;

	public:
		Dialogue();

		virtual void Update();

		virtual void Action();

		void CheckActiveDialogue();
		void DeactivateDialogue();

		friend class XMLTranslator;
	};
}
