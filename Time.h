#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace penguine
{
	class GameTime
	{
	private:
		Clock m_Clock;
		Time m_AbsoluteTime, m_LastTime, m_NewTime;

		float m_DeltaTimeMicro;

	public:
		GameTime();

		void Start();
		void Update();

		float GetTimeInSeconds();
		float GetTimeInMicroSeconds();

		float GetDeltaTime();
		float GetDeltaTimeMilli();
		float GetDeltaTimeMicro();
	};
}