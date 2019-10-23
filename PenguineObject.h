#pragma once

namespace penguine
{
	class Engine;

	class PenguineObject
	{
	public:
		PenguineObject();
		virtual ~PenguineObject();

		virtual void Update();
		virtual void Render();

		Engine* engine;
	};
}