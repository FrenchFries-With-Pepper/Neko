#pragma once
#include"Core.h"

namespace Neko {

	class NEKO_API Application
	{
	public:
		Application();

		virtual ~Application();//��Ϊ�麯��������Sandbox�̳�ʵ��

		void run();
	};


	Application* CreateApplication();
}