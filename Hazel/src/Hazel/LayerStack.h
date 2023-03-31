#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {

	class HAZEL_API LayerStack	// ֻ��Applicationӵ��
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);		// ���뵽������ͷ��������Push��Ϊ�˱�֤��ͨLayerһ����ջ���棬Overlay��������
		void PushOverlay(Layer* overlay);	
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;	// ���������layer������LayerStack��ʵ���������������һ����װ��ջ�׶�Ӧbegin(),��vector�ĺô��ǿ�����/�������
		std::vector<Layer*>::iterator m_LayerInsert;	// �����ĵ�����,��ʼֵΪbegin()����¼�������µ��Ǹ�layer��λ�ã��´λ�����֮ǰ���룬����һֱ����begin()����
	};

}