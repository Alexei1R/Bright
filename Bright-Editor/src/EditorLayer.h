#pragma once
#include "Bright.h"
#include "ScriptingEngine.h"
#include "Paneles/Scripting/Scripting.h"


namespace Bright {




	


	class EditorLayer : public Layer {
	public:
		EditorLayer();
		~EditorLayer();


		virtual void OnAttach()override;
		virtual void OnDetach()override;
		virtual void OnUpdate()override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& event) override;



	private:
		void DrawMenu();



	private:
		Scripting* scripting;
		SREngine* script;

	};




}