#include <Hazel.h>
// Entry Point
#include <Hazel/Core/EntryPoint.h>

#include "SandboxApplication2D.h"

class SandboxApplication : public Hazel::Application
{
public:
	SandboxApplication()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new SandboxApplication2D());
		
	}

	~SandboxApplication()
	{
	}

};

Hazel::Application* Hazel::CreateApplication(ApplicationCommandLineArgs args)
{
	return new SandboxApplication();
}
