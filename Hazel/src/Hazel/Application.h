#pragma once

#include "core.h"
#include "Events/Event.h"

namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// ��������������һ����������Ҫ�ڿͻ���ʵ��
	Application* CreateApplication();
}
