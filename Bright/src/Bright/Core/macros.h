#pragma once
#include "brpch.h"




#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
#define BR_ASSERT(x, ...) { if(!(x)) { BR_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
namespace Bright {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}