#pragma once
#include "srpch.h"

namespace Bright {

	class SREngine {

	public:
		static std::string InitScript();
		static std::string ShutdownScript();

	public:
		static std::string OpenScript();
		static std::string RunScript(std::string script);
		static bool SaveScript(std::string path,std::string script);
		static bool ReloadScript(std::string path,std::string script);

	public:
		static void AddScriptFunction(std::string name, std::function<void()>& function); 
		






	private:






	};





}