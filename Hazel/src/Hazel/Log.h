#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>


namespace Hazel{
	class HAZEL_API Log
	{
	public:
		static void Init();	// 创建消息记录器，并设置消息内容等级，输出格式
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		// 静态变量，在类外（全局）初始化
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// 不需要每次都Hazel::GetCoreLogger()->warn();  这么长去打印一个字符串，因此定义宏
// Hazel前面的冒号是为了确保这些代码移植到其他代码中，能够兼容，比如Hazel外面还可能有一层用户的命名空间 ,他可以通过这样来正确的调用函数SomeNamespace::HZ_CORE_TRACE(a,b,c);
#define HZ_CORE_TRACE(...)		::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...)	::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Cline log macros			  
#define HZ_TRACE(...)			::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)			::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)			::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)			::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CRITICAL(...)		::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
