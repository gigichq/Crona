#pragma once
//#include "core.h"
#include "crona/Window.h"
#include "crona/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent&);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in clinet
	Application* CreateApplication();
}


