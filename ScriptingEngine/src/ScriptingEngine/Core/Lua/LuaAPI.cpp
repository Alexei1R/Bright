#include "srpch.h"
#include "LuaAPI.h"



namespace Bright {
	
	


	

	void LuaAPI::Init()
	{
		L = luaL_newstate();
		luaL_openlibs(L);
	}

	void LuaAPI::Shutdown()
	{
		lua_close(L);
		
		
	}

	std::string LuaAPI::Run(std::string script)
	{
		
		std::string errors;
		
		int error = luaL_loadstring(L, script.c_str());

		if (error)
		{
			std::cerr << "Failed to load Lua code: " << lua_tostring(L, -1) << std::endl;
			errors = lua_tostring(L, -1);
			//lua_close(L);
			return errors;
		}

		// Call the Lua code
		error = lua_pcall(L, 0, 0, 0);

		if (error)
		{
			std::cerr << "Failed to run Lua code: " << lua_tostring(L, -1) << std::endl;
			errors = errors + lua_tostring(L, -1);
			//lua_close(L);
			return errors;
		}
		std::cout << "Lua code Executed";
		return errors;
	}

	void LuaAPI::AddLuaFunction(std::string name, int (*function)(lua_State*))
	{
		
		
		lua_register(L, name.c_str(), function);

	}

}