#pragma once

#ifdef PB_WINDOWS_PLATFORM

extern Peanutbutter::Application* Peanutbutter::CreateApplication();

int main(int argc, char** argv)
{
	Peanutbutter::Log::Init();
	//PB_CORE_WARN("Initialized Log!");
	//int a = 5;
	//PB_ERROR("Hello. Value = {0}", a);

	auto app = Peanutbutter::CreateApplication();
	app->Run();
	delete app;
}

#endif