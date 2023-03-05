#pragma once 
#include "srpch.h"
#include "lua/lua.hpp"



namespace Bright {
	class LuaAPI {
	public:
		
		void Init();
		void Shutdown();
		std::string Run(std::string script);
		void AddLuaFunction(std::string name, int (*function)(lua_State*));
		


	public:
		lua_State* GetLuaState() { return L; };

	private:

		lua_State* L;




	};





}