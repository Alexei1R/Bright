#pragma once
#include "Bright/Core/macros.h"


namespace Bright
{
	class Input
	{
	public :
		static bool IsKeyPresed(int keyCode) { return s_Instance->IsKeyPresedImpl(keyCode); }
		static bool IsMousePresed(int button) { return s_Instance->IsMousePresedImpl(button); }
		static std::pair<double,double> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		static double GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static double GetMouseY() { return s_Instance->GetMouseYImpl(); }


	protected:
		virtual bool IsKeyPresedImpl(int keyCode) = 0;
		virtual bool IsMousePresedImpl(int button) = 0;
		virtual std::pair<double, double> GetMousePosImpl() = 0;
		virtual double GetMouseXImpl() = 0;
		virtual double GetMouseYImpl() = 0;

	private:
		static Input* s_Instance;
	};
}