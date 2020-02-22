#pragma once
#include <SFML/Audio.hpp>
#include "Component.h"

namespace penguine
{
	class Sound : public Component
	{
	private:
		sf::SoundBuffer* m_Buffer;
		sf::Sound* m_Sound;

		bool m_isLoop = false;

	public:
		Sound();

		void LoadFromFile(std::string path);
		void Play();
	};
}
