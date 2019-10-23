#pragma once
#include <string>
#include "penguine/GameObject.h"
#include "penguine/PenguineObject.h"

namespace penguine
{
	class GameObject;

	class Component: public PenguineObject
	{
	protected:
		bool m_IsEnabled;
		std::string m_Name;

		GameObject* m_GameObject;

	public:
		Component();
		virtual ~Component();

		virtual void Update();
		virtual void Render();

		std::string GetName();

		friend class GameObject;
	};
}