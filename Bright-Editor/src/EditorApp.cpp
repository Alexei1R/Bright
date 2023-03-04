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







int plot(lua_State* L)
{
	// Get the table argument from the Lua stack
	luaL_checktype(L, 1, LUA_TTABLE);

	// Loop through the table and print each element
	int table_len = luaL_len(L, 1);
	for (int i = 1; i <= table_len; i++)
	{
		lua_pushinteger(L, i);
		lua_gettable(L, 1);
		float data = (float)lua_tonumber(L, -1);
		std::cout << data << std::endl;
		lua_pop(L, 1);
	}

	return 0;
}


int main() {

	Bright::Log::Init();
	BR_TRACE("Log Init");
	Bright::Application* app = new Bright::EditorApp();
	Bright::SREngine script;

	script.AddScriptFunction("plot", plot);


	std::thread th(
		[&]()
		{
			script.RunScript(R"(
				local arr = {}
				
				-- Fill the array with random integers
				for i = 1, 200 do
				  arr[i] = math.sin(i)
				end
				plot(arr)
				print("test")
				)"

			);

		}
	);
	th.detach();
	
	app->Run();
	delete app;
	
	
	return 0;
}