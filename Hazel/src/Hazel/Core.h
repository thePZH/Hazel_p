#pragma once

// dllexport dllimportֻ��windows��Ч
#ifdef HZ_PLATFORM_WINDOWS 
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only surpport windows!	// ���û�ж���ú꣬������ھ���
#endif // HZ_PLATFORM_WINDOWS 

#define BIT(x) (1 << x)