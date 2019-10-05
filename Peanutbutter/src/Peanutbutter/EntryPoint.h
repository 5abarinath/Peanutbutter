#pragma once

#ifdef PB_WINDOWS_PLATFORM

extern Peanutbutter::Application* Peanutbutter::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Peanutbutter::CreateApplication();
	app->Run();
	delete app;
}

#endif