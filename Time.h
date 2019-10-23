#pragma once
#include <SFML/Graphics.hpp>

namespace penguine
{
	class GameTime
	{
	private:
		sf::Clock m_Clock, m_DeltaClock;
		sf::Time m_AbsoluteTime, m_LastUpdate;

		float m_DeltaTimeMicro;

	public:
		GameTime();

		void Start();
		void Update();
		void ResetClock();

		sf::Time GetLastUpdate();

		float GetTimeInSeconds();
		float GetTimeInMicroSeconds();

		float GetDeltaTime();
		float GetDeltaTimeMilli();
		float GetDeltaTimeMicro();
	};
}