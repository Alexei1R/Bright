#pragma once 
#include "srpch.h"
#include "lua/lua.hpp"



namespace Bright {
	class LuaAPI {
	public:
		LuaAPI();
		~LuaAPI();

		void Run(std::string script);
		void AddScriptFunction(std::string name, std::function<void()>& function);
		


	private:

		lua_State* L;




	};





}