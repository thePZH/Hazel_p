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
		// ����layer������"�����"Ϊ�µ�layerλ��
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	// OverlayӦ�÷����������ˣ�������
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	// poplayer ������delete��ֻ�ǳ�ջ��Ҳ��ĳ��ʱ�����ѹ������
	void LayerStack::PopLayer(Layer* layer)
	{
		// ����1�������--���������m_LayerInsert��ָ���ɾ��Ԫ�صĺ��棬��Ӧ��--�������ǰ��Ӧ�ò���--�ɣ�
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