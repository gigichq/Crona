#pragma once

#ifdef CA_PLATFORM_WINDOWS
	#ifdef CRONA_BUILD_DLL
		#define CRONA_API __declspec(dllexport)
	#else
		#define CRONA_API __declspec(dllimport)
	#endif
#else
	#error Corna only support windows!
#endif

#define BIT(x) (1 << x)