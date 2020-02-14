#pragma once

#ifdef CA_PLATFORM_WINDOWS
extern Crona::Application* Crona::CreateApplication();
int main(int argc, char** argv)
{
	Crona::Log::Init();
	CA_CORE_WARN("Star Crona Engine.");
	int a = 5;
	CA_INFO("Log Info:{0}", a);

	auto app = Crona::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#else
#error Corna only support windows!
#endif