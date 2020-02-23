#include "Sound.h"

namespace penguine
{
	Sound::Sound()
	{
		m_Buffer = new sf::SoundBuffer();
		m_Sound = new sf::Sound();
	}

	void Sound::LoadFromFile(std::string path)
	{
		if (!m_Buffer->loadFromFile(path))
		{
			std::cout << "Couldn't load Sound at " << path << "." << std::endl;
		}

		m_Sound->setBuffer(*m_Buffer);
	}

	void Sound::Play()
	{
		m_Sound->play();
	}
}