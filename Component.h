#pragma once
#include <string>
#include "penguine/GameObject.h"

namespace penguine
{
	class GameObject;

	class Component
	{
	protected:
		bool m_IsEnabled;
		std::string m_Name;

		GameObject* m_GameObject;

	public:
		Component();
		virtual ~Component();

		virtual void Update();

		std::string GetName();

		friend class GameObject;
	};
}