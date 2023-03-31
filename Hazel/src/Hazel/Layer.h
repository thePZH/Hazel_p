#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");	// Ϊlayer���������ڵ��ԣ�DIST�汾��Ӧ����
		virtual ~Layer();

		virtual void OnAttach() {}			// ��layer��ѹջʱ
		virtual void OnDetach() {}			// ��layer����ջʱ
		virtual void OnUpdate() {}			// Ӧ�ó���ÿ֡���µ�����
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;

		// TODO bool�����Ƿ����øò㣨Ҳ������layer stack�ж��壩
	};

}