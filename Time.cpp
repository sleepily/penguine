#include <SFML/Graphics.hpp>
#include "penguine/Time.h"

namespace penguine
{
	GameTime::GameTime()
	{
		m_Clock = Clock();
		m_DeltaTimeMicro = 0.0f;
	}

	void GameTime::Start()
	{
		m_AbsoluteTime = m_LastTime = m_NewTime = Time();
	}

	void GameTime::Update()
	{
		m_AbsoluteTime += m_LastTime;
		m_LastTime = m_NewTime;
		m_NewTime = m_Clock.restart();
		m_DeltaTimeMicro = m_NewTime.asMicroseconds();
	}

	float GameTime::GetTimeInSeconds()
	{
		return m_AbsoluteTime.asSeconds();
	}

	float GameTime::GetTimeInMicroSeconds()
	{
		return m_AbsoluteTime.asMicroseconds();
	}

	float GameTime::GetDeltaTime()
	{
		return m_DeltaTimeMicro / 1000000.0f;
	}

	float GameTime::GetDeltaTimeMilli()
	{
		return m_DeltaTimeMicro / 1000.0f;
	}

	float GameTime::GetDeltaTimeMicro()
	{
		return m_DeltaTimeMicro;
	}
}