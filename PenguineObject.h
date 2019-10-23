#pragma once
#include <iostream>

namespace penguine
{
	class Engine;

	class PenguineObject
	{
	protected:
		std::string m_Name;

	public:
		PenguineObject();
		virtual ~PenguineObject();

		virtual void Update();
		virtual void Render();

		virtual void SetEngine(Engine* engine);

		virtual std::string ToString();
		std::string GetName();

		Engine* engine;
	};
}