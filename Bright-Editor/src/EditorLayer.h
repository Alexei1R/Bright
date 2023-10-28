#pragma once
#include "Bright.h"
#include "ScriptingEngine.h"
#include "Paneles/Scripting/Scripting.h"
#include "Paneles/Plotter/Plotter.h"


namespace Bright {




	


	class EditorLayer : public Layer {
	public:
		EditorLayer(unsigned int framebuffer);
		~EditorLayer();


		virtual void OnAttach()override;
		virtual void OnDetach()override;
		virtual void OnUpdate()override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& event) override;


	private:
		void DrawMenu();



	private:


		unsigned int m_FrameBuffer;
		SREngine* script;
		Scripting* scripting;

	};




}