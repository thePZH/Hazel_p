#pragma once

#include "core.h"

namespace Hazel{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// 仅仅是引擎端里的一个声明，需要在客户端实现
	Application* CreateApplication();
}
