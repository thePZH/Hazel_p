#pragma once

#ifdef HZ_PLATFORM_WINDOWS
// �����������������ĳ���ⲿ���뵥Ԫ�У��ͻ���ʵ�֣�
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
