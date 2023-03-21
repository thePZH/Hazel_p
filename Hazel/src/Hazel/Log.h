#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>


namespace Hazel{
	class HAZEL_API Log
	{
	public:
		static void Init();	// ������Ϣ��¼������������Ϣ���ݵȼ��������ʽ
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		// ��̬�����������⣨ȫ�֣���ʼ��
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// ����Ҫÿ�ζ�Hazel::GetCoreLogger()->warn();  ��ô��ȥ��ӡһ���ַ�������˶����
// Hazelǰ���ð����Ϊ��ȷ����Щ������ֲ�����������У��ܹ����ݣ�����Hazel���滹������һ���û��������ռ� ,������ͨ����������ȷ�ĵ��ú���SomeNamespace::HZ_CORE_TRACE(a,b,c);
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
