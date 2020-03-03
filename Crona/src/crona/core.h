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

#ifdef CA_DEBUG
#define CA_ENABLE_ASSERTS
#endif

#ifdef CA_ENABLE_ASSERTS
#define CA_ASSERT(x, ...) { if(!(x)) { CA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define CA_CORE_ASSERT(x, ...) { if(!(x)) { CA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define CA_ASSERT(x, ...)
#define CA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn,this, std::placeholders::_1)