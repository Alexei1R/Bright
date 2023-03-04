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
	BR_TRACE("Log Init")
	Bright::Application* app = new Bright::EditorApp();
	Bright::LuaAPI lua;
	std::thread th(
		[&]() {
			lua.Run(R"(
				local arr = {}
				
				-- Fill the array with random integers
				for i = 1, 20000 do
				  arr[i] = math.random(1, 100)
				end
				plot(arr)
				)"
			); 
		}
	
	);
	th.detach();
	
	app->Run();
	delete app;
	
	
	return 0;
}