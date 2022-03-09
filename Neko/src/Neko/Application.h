#pragma once
#include"Core.h"

namespace Neko {

	class NEKO_API Application
	{
	public:
		Application();

		virtual ~Application();//设为虚函数，将被Sandbox继承实现

		void run();
	};


	Application* CreateApplication();
}