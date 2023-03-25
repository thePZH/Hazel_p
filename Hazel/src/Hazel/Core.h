#pragma once

// dllexport dllimport只在windows有效
#ifdef HZ_PLATFORM_WINDOWS 
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only surpport windows!	// 如果没有定义该宏，则编译期警告
#endif // HZ_PLATFORM_WINDOWS 

#define BIT(x) (1 << x)