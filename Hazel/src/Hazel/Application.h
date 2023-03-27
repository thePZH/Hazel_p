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
		std::unique_ptr<Window> m_Window;	// 多态,且程序结束后自动释放
		bool m_Running = true;
	};

	// 仅仅是引擎端里的一个声明，需要在客户端实现
	Application* CreateApplication();
}
