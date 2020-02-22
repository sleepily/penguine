#pragma once
#include <string>
#include "PenguineObject.h"
#include "GameObject.h"

namespace penguine
{
	class GameObject;

	class Component: public PenguineObject
	{
	protected:
		bool m_IsEnabled = true;

		GameObject* m_GameObject;

	public:
		Component();
		virtual ~Component();

		virtual void Update();
		virtual void Render();

		virtual std::string ToString();

		friend class GameObject;
		friend class XMLTranslator;
	};
}