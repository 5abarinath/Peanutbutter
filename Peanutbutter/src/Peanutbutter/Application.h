#pragma once

#include "Core.h"

namespace Peanutbutter 
{

	class PB_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();
}