#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel {
	// windows上的窗口是用GLFW实现的
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;	// 每帧一次在app中调用

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData	
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;	// GLFW窗口产生事件后，我们会将其转换成引擎事件(Event.h)，然后传递给引擎层，通过此回调函数来传递。在Application构造时指定此回调函数
		};

		WindowData m_Data;// 本窗口的信息，传给GLFW的数据内容，没必要传递整个类给他
	};

}