#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");	// 为layer命名仅用于调试，DIST版本不应该有
		virtual ~Layer();

		virtual void OnAttach() {}			// 当layer被压栈时
		virtual void OnDetach() {}			// 当layer被出栈时
		virtual void OnUpdate() {}			// 应用程序每帧更新调用它
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;

		// TODO bool控制是否启用该层（也可以在layer stack中定义）
	};

}