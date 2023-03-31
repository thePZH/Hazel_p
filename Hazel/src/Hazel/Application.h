#pragma once

#include "core.h"

#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;	// 多态,且程序结束后自动释放
		bool m_Running = true;
		LayerStack m_LayerStack;			// 栈上创建，生命周期随类
	};

	// 仅仅是引擎端里的一个声明，需要在客户端实现
	Application* CreateApplication();
}
