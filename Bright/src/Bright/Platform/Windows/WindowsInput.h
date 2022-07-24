#pragma once
#include "Bright/Core/Input.h"

namespace Bright
{
	class WindowsInput : public Input
	{


	protected:
		virtual bool IsKeyPresedImpl(int keyCode)override;
		virtual bool IsMousePresedImpl(int button)override;
		std::pair<double, double> GetMousePosImpl()override;
		virtual double GetMouseXImpl() override;
		virtual double GetMouseYImpl() override;


	
	};
}
