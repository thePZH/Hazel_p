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
			设置C++日志记录格式为"%^[%T] %n: %v%$"
			"%^" 和 "%$": 这是颜色代码，告诉记录器以某种颜色打印它们之间的文本。在这种情况下，"%^" 设置为一个明亮的颜色，而 "%$" 相当于结束符将其重置回默认颜色。
			"[%T]": 打印当前时间以特定的格式。确切的格式取决于 "%T" 部分指定的内容。
			"%n": 打印记录器的名称。记录器名称可以用来区分不同的日志记录器，例如在多个线程或组件中使用时。
			"%v": 打印日志消息的实际内容。
		*/
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// 初始化静态变量 记录器
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);	// 消息级别，trace为最详细的级别
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}


