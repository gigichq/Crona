#include <crona.h>

class ExampleLayer : public Crona::Layer
{
public :
	ExampleLayer()
		:Layer("ExampleLayer")
	{}

	void OnUpdate() override
	{
		CA_INFO("ExampleLayer:Update");
	}

	void OnEvent(Crona::Event& e) override
	{
		CA_TRACE("ExampleLayer:Event");
		//CA_CORE_TRACE("{0}", e.ToString());
	}
};

class SandBox : public Crona::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Crona::ImGuiLayer());
	}

	~SandBox()
	{

	}
};

Crona::Application* Crona::CreateApplication()
{
	return new SandBox();
}