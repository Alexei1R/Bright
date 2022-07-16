#pragma once 




#define BR_ASSERT(x, ...) { if(!(x)) { BR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }



#define BIT(x) (1 << x)