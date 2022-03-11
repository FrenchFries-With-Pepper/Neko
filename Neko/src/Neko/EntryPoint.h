#pragma once


#ifdef NEKO_PLATFORM_WINDOWS
extern Neko::Application* Neko::CreateApplication();

int main(int argc, char** argv) {
	Neko::Log::init();
	//Neko::Log::getCoreLogger()->warn("Initialized logging!");
	NEKO_CORE_WARN("Initialized logging!");
	NEKO_CLIENT_INFO("Hello");
	auto app = Neko::CreateApplication();
	app->run();
	delete app;
}
#endif