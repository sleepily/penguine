#include <SFML/Graphics.hpp>
#include <iostream>
#include "penguine/Time.h"

namespace penguine
{
	GameTime::GameTime()
	{
		m_Clock = m_DeltaClock = sf::Clock();
		m_DeltaTimeMicro = 0.0f;
	}

	void GameTime::Start()
	{
		m_AbsoluteTime = m_LastUpdate = sf::Time();
	}

	void GameTime::ResetClock()
	{
		m_AbsoluteTime = m_Clock.getElapsedTime();
	}

	void GameTime::Update()
	{
		m_DeltaTimeMicro = m_AbsoluteTime.asMicroseconds() - m_LastUpdate.asMicroseconds();
		m_LastUpdate = m_AbsoluteTime;
	}

	sf::Time GameTime::GetLastUpdate()
	{
		return m_LastUpdate;
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