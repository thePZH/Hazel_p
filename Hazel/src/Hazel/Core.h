#pragma once

// dllexport dllimportֻ��windows��Ч
#ifdef HZ_PLATFORM_WINDOWS 
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only surpport windows!
#endif // HZ_PLATFORM_WINDOWS 
