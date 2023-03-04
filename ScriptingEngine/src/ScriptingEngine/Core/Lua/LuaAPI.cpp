#include "srpch.h"
#include "LuaAPI.h"



namespace Bright {
	
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
			int data = (int)lua_tonumber(L, -1);
			std::cout << data << std::endl;
			lua_pop(L, 1);
		}

		return 0;
	}


	LuaAPI::LuaAPI()
	{
		L = luaL_newstate();
		luaL_openlibs(L);
	}

	LuaAPI::~LuaAPI()
	{
		lua_close(L);
	}

	void LuaAPI::Run(std::string script)
	{
		lua_register(L, "plot", plot);

		
		int error = luaL_loadstring(L, script.c_str());

		if (error)
		{
			std::cerr << "Failed to load Lua code: " << lua_tostring(L, -1) << std::endl;
			lua_close(L);
		}

		// Call the Lua code
		error = lua_pcall(L, 0, 0, 0);

		if (error)
		{
			std::cerr << "Failed to run Lua code: " << lua_tostring(L, -1) << std::endl;
			lua_close(L);
		}

	}

	void LuaAPI::AddScriptFunction(std::string name, std::function<void()>& function)
	{
	}

}