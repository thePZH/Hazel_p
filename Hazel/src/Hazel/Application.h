#pragma once

#include "core.h"
#include "Events/Event.h"
#include "Window.h"
namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;	// ��̬,�ҳ���������Զ��ͷ�
		bool m_Running = true;
	};

	// ��������������һ����������Ҫ�ڿͻ���ʵ��
	Application* CreateApplication();
}
