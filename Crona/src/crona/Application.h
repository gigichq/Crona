#pragma once
//#include "core.h"
#include "crona/Window.h"
#include "crona/events/ApplicationEvent.h"

namespace Crona
{
	class CRONA_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event&);
	private:
		bool OnWindowClose(WindowCloseEvent&);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in clinet
	Application* CreateApplication();
}


