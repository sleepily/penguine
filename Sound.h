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

		bool m_IsLoop = false;
		bool m_IsAutoplay = false;

	public:
		Sound();

		virtual void DoAction(std::string actionType);

		virtual void Update();

		void LoadFromFile(std::string path);
		void Play();

		friend class XMLTranslator;
	};
}
