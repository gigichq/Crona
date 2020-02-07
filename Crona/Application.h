#pragma once
#include "core.h"

namespace Crona
{
	class CRONA_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	//To be defined in clinet
	Application* CreateApplication();
}


