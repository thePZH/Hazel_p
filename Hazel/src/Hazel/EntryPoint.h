#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// �����������������ĳ���ⲿ���뵥Ԫ�У��ͻ���ʵ�֣�
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hazel::CreateApplication();
	app->Run();

	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
