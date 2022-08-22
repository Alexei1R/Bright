#pragma once 
#include "Bright/Core/macros.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Bright {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static Ref<spdlog::logger> s_Logger;
	};

}

// Core log macros
#define BR_TRACE(...)    ::Bright::Log::GetLogger()->trace(__VA_ARGS__);
#define BR_INFO(...)     ::Bright::Log::GetLogger()->info(__VA_ARGS__);
#define BR_WARN(...)     ::Bright::Log::GetLogger()->warn(__VA_ARGS__);
#define BR_ERROR(...)    ::Bright::Log::GetLogger()->error(__VA_ARGS__);
#define BR_CRITICAL(...) ::Bright::Log::GetLogger()->critical(__VA_ARGS__);






