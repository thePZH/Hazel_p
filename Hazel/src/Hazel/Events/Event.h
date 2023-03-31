#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

namespace Hazel {

	// Hazel���¼�Ŀǰ�������¼�����ζ����һ���������ͱ����������ַ��ʹ���֮�������¼�������ƣ���update�׶�ȡ��������

	enum class EventType	// ��һЩ�����������������͵��¼���������¼���������һ������ʵ�֣���ͬĿ¼�µ������ط�
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,	
		AppTick, AppUpdate, AppRender,											
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory	// �ö����Ʊ�ʾ�ģ��������λ���㣬��ʾ�������Щ�¼�
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

// ΪʲôҪ�������¼�����ʵ������������̬����д������麯������̬���ã�
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
	public:
		bool Handled = false; // �¼��Ƿ��ѱ�����������ĳһ�㴦���а������Ϊtrue��ʹ�ô��¼�����������´���

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;					// ����debug
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }	// ����debug���������<<���ؾͶ���

		inline bool IsInCategory(EventCategory category)	// �жϱ��¼��Ƿ��Ǵ��������е�һ��
		{
			return GetCategoryFlags() & category;
		}
	};

	// ����event��type�������¼��ķ���
	// �ⲿ�����κ��¼�����һ��EventDispatcherʵ����Ȼ�����N��Dispatch�������벻ͬ���¼�������
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;	// T�����������¼���
	public:
		EventDispatcher(Event& event)	
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)	// �β�Ϊ����m_Event�ĺ��� bool(*func)(T&)
		{
			// ��鱻�ַ��¼��������Ƿ���ģ�����T��������ƥ��
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;	// ��Ҫ�ַ����¼�
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)	// ����<<��������������spdlog��ӡ�����Զ������������
	{
		return os << e.ToString();
	}
}