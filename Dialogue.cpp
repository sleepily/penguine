#include "Dialogue.h"

namespace penguine
{
	Dialogue::Dialogue()
	{
		m_TextBox = new TextBox();
		m_TextBox->SetVisibility(false);
	}

	void Dialogue::Update()
	{
		m_TextBox->Update();

		if (m_TextBox->GetVisibility())
			CheckActiveDialogue();
	}

	void Dialogue::Action()
	{
		m_StartTime = engine->GetTime()->GetTimeInSeconds();

		m_TextBox->SetVisibility(true);
	}

	void Dialogue::CheckActiveDialogue()
	{
		if (engine->GetTime()->GetTimeInSeconds() >= m_StartTime + m_DisplayTime)
			DeactivateDialogue();
	}

	void Dialogue::DeactivateDialogue()
	{
		m_TextBox->SetVisibility(false);
		m_StartTime = 0;
	}
}