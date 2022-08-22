#include "EditorLayer.h"

namespace Bright {
	EditorLayer::EditorLayer()
		:Layer("EditorLayer")
	{
	}


	void EditorLayer::OnAttach() 
	{
	}
	void EditorLayer::OnDetach() 
	{
	}
	void EditorLayer::OnUpdate() 
	{
	}
	void EditorLayer::OnImGuiRender() 
	{

		ImGui::Begin("Settings");

		ImGui::Text("Some text");

		ImGui::End();
	}
	void EditorLayer::OnEvent(Event& event) {}

}