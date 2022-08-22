#pragma once
#include "Bright/Core/Layers/Layer.h"


namespace Bright {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& e) override;

		void Begin();
		void End();


		void SetDarkThemeColors();
	};
}
