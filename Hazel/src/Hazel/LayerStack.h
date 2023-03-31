#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {

	class HAZEL_API LayerStack	// 只被Application拥有
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);		// 插入到容器的头部，两个Push是为了保证普通Layer一定在栈下面，Overlay在最上面
		void PushOverlay(Layer* overlay);	
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;	// 核心是这个layer容器，LayerStack类实际上是这个容器的一个包装，栈底对应begin(),用vector的好处是可以正/反向遍历
		std::vector<Layer*>::iterator m_LayerInsert;	// 插入点的迭代器,初始值为begin()，记录容器最新的那个layer的位置，下次会在它之前插入，好像一直都是begin()啊？
	};

}