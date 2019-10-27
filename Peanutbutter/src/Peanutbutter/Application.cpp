#include "pch.h"

#include "Application.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"

namespace Peanutbutter
{
	Application::Application() 
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		MouseButtonPressedEvent e(1);
		PB_TRACE(e.ToString());

		while (true);
	}
}