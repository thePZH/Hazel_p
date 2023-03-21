#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Hazel {
	// ��̬��Ա�����������ٶ���һ�Σ�Ϊ��Ա���������ڴ�ռ�
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;	
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() 
	{
		/*
			�ο���ʽ�����÷�ʽ https://github.com/gabime/spdlog/wiki/3.-Custom-formatting 
			����C++��־��¼��ʽΪ"%^[%T] %n: %v%$"
			"%^" �� "%$": ������ɫ���룬���߼�¼����ĳ����ɫ��ӡ����֮����ı�������������£�"%^" ����Ϊһ����������ɫ���� "%$" �൱�ڽ������������û�Ĭ����ɫ��
			"[%T]": ��ӡ��ǰʱ�����ض��ĸ�ʽ��ȷ�еĸ�ʽȡ���� "%T" ����ָ�������ݡ�
			"%n": ��ӡ��¼�������ơ���¼�����ƿ����������ֲ�ͬ����־��¼���������ڶ���̻߳������ʹ��ʱ��
			"%v": ��ӡ��־��Ϣ��ʵ�����ݡ�
		*/
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// ��ʼ����̬���� ��¼��
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);	// ��Ϣ����traceΪ����ϸ�ļ���
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}


