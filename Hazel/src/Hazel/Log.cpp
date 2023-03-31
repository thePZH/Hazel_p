#include "hzpch.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Hazel {
	// 静态成员必须在类外再定义一次，为成员变量分配内存空间
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;	
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() 
	{
		/*
			参考格式化设置方式 https://github.com/gabime/spdlog/wiki/3.-Custom-formatting 
			这个函数，指定spdlog的消息记录格式
			"%^" 和 "%$"	: 告诉记录器以某种颜色打印它们之间的文本。例如，%^red%$ 表示将文本设置为红色高亮。若未指定颜色，则以默认的颜色输出（不同消息类型，默认颜色也不同）
			"[%T]"		: 输出当前的时间戳，精确到秒。
			"%n"		: 打印记录器的名称。记录器名称可以用来区分不同的日志记录器，例如在多个线程或组件中使用时。
			：			：输出一个冒号
			"%v"		: 打印日志消息的实际内容（即使用接口时输入的字符串）。
		*/
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// 初始化静态变量 记录器
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");	// 记录器1，命名为HAZEL
		s_CoreLogger->set_level(spdlog::level::trace);		// 消息级别，trace为最详细的级别
		s_ClientLogger = spdlog::stdout_color_mt("APP");	// 记录器2，命名为APP
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}


