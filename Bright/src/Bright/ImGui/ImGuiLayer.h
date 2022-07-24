#pragma once
#include "brpch.h"
#include "Bright/Core/Layer.h"
#include "Bright/Core/Application.h"


namespace Bright
{
	class ImGuiLayer : public Layer
	{	
	public:

		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach()override;
		virtual void OnDetach()override;
	
		virtual void OnImGuiRender() override;

		void Begin()override;
		void End()override;
	
	private:
	
	
	
	
	};
}
