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
		m_Sound->setLoop(m_IsLoop);
		m_Sound->play();
	}

	void Sound::DoAction(std::string actionType)
	{
		if (actionType == "click" && m_ActionType == "click")
			Play();
	}

	void Sound::Update()
	{
		if (m_IsAutoplay)
			if (m_Sound->getBuffer())
			{
				m_IsAutoplay = false;
				Play();
			}
	}
}