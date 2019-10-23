#pragma once
#include <string>
#include "penguine/GameObject.h"

namespace penguine
{
	class GameObject;

	class Component
	{
	protected:

		std::string m_Name;

	public:
		Component();
		virtual ~Component();

		virtual void Update();

		GameObject* m_GameObject;

		std::string GetName();

		friend class GameObject;
	};
}