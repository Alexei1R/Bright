#pragma once
#include "Bright.h"
#include "ScriptingEngine.h"
#include "EditorLayer.h"



namespace Bright {
	class EditorApp : public Application {
	public:
		EditorApp() {
			PushLayer(new EditorLayer());
		}
		~EditorApp() {}
	};

}










int main() {

	Bright::Log::Init();
	BR_TRACE("Log Init");
	Bright::Application* app = new Bright::EditorApp();
	app->Run();
	delete app;
	
	
	return 0;
}