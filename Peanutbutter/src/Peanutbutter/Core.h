#pragma once

#ifdef PB_WINDOWS_PLATFORM
	#ifdef PB_BUILD_DLL
		#define PB_API __declspec(dllexport)
	#else
		#define PB_API __declspec(dllimport)
	#endif
#else
	#error Peanutbutter only supports Windows!
#endif

#define BIT(x) (1 << x)
