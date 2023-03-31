#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {

	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		// 插入layer并更新"插入点"为新的layer位置
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	// Overlay应该放在容器最后端，最后绘制
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	// poplayer 并不会delete，只是出栈（也许某个时候会再压回来）
	void LayerStack::PopLayer(Layer* layer)
	{
		// 问题1：这里的--操作，如果m_LayerInsert是指向的删除元素的后面，则应该--，如果在前面应该不用--吧？
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;	
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

}