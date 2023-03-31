#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel {
	// windows�ϵĴ�������GLFWʵ�ֵ�
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;	// ÿ֡һ����app�е���

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

			EventCallbackFn EventCallback;	// GLFW���ڲ����¼������ǻὫ��ת���������¼�(Event.h)��Ȼ�󴫵ݸ�����㣬ͨ���˻ص����������ݡ���Application����ʱָ���˻ص�����
		};

		WindowData m_Data;// �����ڵ���Ϣ������GLFW���������ݣ�û��Ҫ�������������
	};

}