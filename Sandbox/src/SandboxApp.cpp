#include <Peanutbutter.h>

class Sandbox : public Peanutbutter::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox() 
	{
	}
};

Peanutbutter::Application* Peanutbutter::CreateApplication()
{
	return new Sandbox();
}