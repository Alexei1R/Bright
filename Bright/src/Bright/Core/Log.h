#pragma once
#include "brpch.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Bright
{

	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}



// Client log macros
#define BR_TRACE(...)         ::Bright::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BR_INFO(...)          ::Bright::Log::GetClientLogger()->info(__VA_ARGS__);
#define BR_WARN(...)          ::Bright::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BR_ERROR(...)         ::Bright::Log::GetClientLogger()->error(__VA_ARGS__);
#define BR_CRITICAL(...)      ::Bright::Log::GetClientLogger()->critical(__VA_ARGS__);