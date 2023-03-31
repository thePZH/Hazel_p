#pragma once

#ifdef HZ_PLATFORM_WINDOWS
// 先声明有这个东西在某个外部翻译单元中（客户端实现）
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{	
	Hazel::Log::Init();
	HZ_CORE_WARN("hhhh");
	int a = 0;
	HZ_CRITICAL("bbbb Var = {0}", a);
	auto app = Hazel::CreateApplication();
	app->Run();

	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
