#include <crona.h>

class SandBox : public Crona::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

Crona::Application* Crona::CreateApplication()
{
	return new SandBox();
}