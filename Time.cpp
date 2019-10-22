#include <SFML/Graphics.hpp>
#include "penguine/Time.h"

namespace penguine
{
	GameTime::GameTime()
	{
		m_Clock = Clock();
		m_DeltaTimeMicro = 0.0f;
	}

	void GameTime::Update()
	{
		m_LastTime = m_NewTime;
		m_NewTime = m_Clock.restart();
	}
	float GameTime::GetTimeInSeconds()
	{
		return m_NewTime.asSeconds();
	}
	float GameTime::GetDeltaTime()
	{
		return m_DeltaTimeMicro / 1000.0f;
	}
	float GameTime::GetDeltaTimeMicro()
	{
		return m_DeltaTimeMicro;
	}
}