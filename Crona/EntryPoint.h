#pragma once

#ifdef CA_PLATFORM_WINDOWS
extern Crona::Application* Crona::CreateApplication();
int main(int argc, char** argv)
{
	printf("Crona Engine");
	auto app = Crona::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#else
#error Corna only support windows!
#endif