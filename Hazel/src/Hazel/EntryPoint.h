#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// 先声明有这个东西在某个外部翻译单元中（客户端实现）
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hazel::CreateApplication();
	app->Run();

	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
