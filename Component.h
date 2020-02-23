#pragma once
#include <string>
#include <vector>
#include "PenguineObject.h"
#include "GameObject.h"

namespace penguine
{
	class GameObject;

	class Component: public PenguineObject
	{
	protected:
		bool m_IsEnabled = true;

		std::string m_ActionType = "none";

		GameObject* m_GameObject;

	public:
		Component();
		virtual ~Component();

		virtual void Update();
		virtual void Render();

		virtual void DoAction(std::string actionType);

		void SetActionType(std::string type);

		virtual std::string ToString();

		friend class GameObject;
		friend class XMLTranslator;
	};
}