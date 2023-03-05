#pragma once
#include "srpch.h"
#include "Lua/LuaAPI.h"

namespace Bright {

	struct FunctionARG
	{
		std::string name;
		int (*function)(lua_State*);


	};

	class SREngine {
	public:
		SREngine();
		~SREngine();


	public:
		
		void Restart();

	public:
		std::string OpenScript();
		std::string RunScript(std::string script);
		bool SaveScript(std::string path,std::string script);
		bool ReloadScript(std::string path,std::string script);

	public:
		void AddScriptFunction(std::string name , int (*function)(lua_State*));
		



	private:
		void InitScript();
		void ShutdownScript();


	private:

		Bright::LuaAPI m_Lua;
		std::vector<FunctionARG> m_FunctionARG;


	};





}