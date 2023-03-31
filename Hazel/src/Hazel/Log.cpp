#include "hzpch.h"
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
			���������ָ��spdlog����Ϣ��¼��ʽ
			"%^" �� "%$"	: ���߼�¼����ĳ����ɫ��ӡ����֮����ı������磬%^red%$ ��ʾ���ı�����Ϊ��ɫ��������δָ����ɫ������Ĭ�ϵ���ɫ�������ͬ��Ϣ���ͣ�Ĭ����ɫҲ��ͬ��
			"[%T]"		: �����ǰ��ʱ�������ȷ���롣
			"%n"		: ��ӡ��¼�������ơ���¼�����ƿ����������ֲ�ͬ����־��¼���������ڶ���̻߳������ʹ��ʱ��
			��			�����һ��ð��
			"%v"		: ��ӡ��־��Ϣ��ʵ�����ݣ���ʹ�ýӿ�ʱ������ַ�������
		*/
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// ��ʼ����̬���� ��¼��
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");	// ��¼��1������ΪHAZEL
		s_CoreLogger->set_level(spdlog::level::trace);		// ��Ϣ����traceΪ����ϸ�ļ���
		s_ClientLogger = spdlog::stdout_color_mt("APP");	// ��¼��2������ΪAPP
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}


