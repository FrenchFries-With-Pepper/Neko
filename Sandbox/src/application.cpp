#include<Neko.h>

class Sandbox :public Neko::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Neko::Application* Neko::CreateApplication() {
	return new Sandbox();
}