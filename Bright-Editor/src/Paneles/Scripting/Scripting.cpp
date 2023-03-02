#include "brpch.h"
#include "Scripting.h"



namespace Bright {
	Scripting::Scripting()
	{
		//lOAD IMAGES ICONS
		int m_Width = 0;
		int m_Height = 0;

		
		bool ret = LoadTextureFromFile("ASSETS/icons/play.png", &m_StartTexture, &m_Width, &m_Height);
		IM_ASSERT(ret);

		ret = LoadTextureFromFile("ASSETS/icons/newfile.png", &m_ImportTexture, &m_Width, &m_Height);
		IM_ASSERT(ret);

		ret = LoadTextureFromFile("ASSETS/icons/openfolder.png", &m_OpenTexture, &m_Width, &m_Height);
		IM_ASSERT(ret);
		
		ret = LoadTextureFromFile("ASSETS/icons/save.png", &m_SaveTexture, &m_Width, &m_Height);
		IM_ASSERT(ret);


	}
	void Scripting::GetDrawData()
	{
		





		//BEGIN WINDOW
		ImGui::Begin("Script",false, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
		ImVec2 m_WSize = ImGui::GetWindowSize();

		ImGui::Columns(2);
		ImGui::SetColumnOffset(1, (float)m_ButtonWidth);

		{//Left side
			ImGui::PushStyleColor(ImGuiCol_Button,			ImVec4(0.25, 0.25, 0.25, 0.0));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered,	ImVec4(0.2f, 0.2f, 0.2f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive,	ImVec4(0.2f, 0.2f, 0.2f, 0.7f));
			
			ImGui::Spacing();

			if (ImGui::ImageButton((void*)(intptr_t)m_StartTexture, ImVec2(25, 25), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), 1, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(1.0f, 1.0f, 1.0f, 1.0f))) {

			}

			ImGui::Spacing();
			if (ImGui::ImageButton((void*)(intptr_t)m_ImportTexture, ImVec2(25, 25), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), 1, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(1.0f, 1.0f, 1.0f, 1.0f))) {

			}

			ImGui::Spacing();
			if (ImGui::ImageButton((void*)(intptr_t)m_OpenTexture, ImVec2(25, 25), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), 1, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(1.0f, 1.0f, 1.0f, 1.0f))) {
			
			}
			
			
			ImGui::Spacing();
			if (ImGui::ImageButton((void*)(intptr_t)m_SaveTexture, ImVec2(25, 25), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), 1, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(1.0f, 1.0f, 1.0f, 1.0f))) {
			
			}




			ImGui::PopStyleColor(3);
		}


		
		ImGui::NextColumn();
		{//RIGHT SIDE
		
			ImGui::Spacing();
			m_TextEditor.SetShowWhitespaces(false);
			m_TextEditor.SetReadOnly(false);
			m_TextEditor.SetPalette(TextEditor::GetDarkPalette());
			m_TextEditor.SetLanguageDefinition(TextEditor::LanguageDefinition::CPlusPlus());

			m_TextEditor.Render("Scripting", ImVec2(m_WSize.x - 108, (m_WSize.y - m_ButtonWidth) - 10));

		
		}


		//END WINDOW
		ImGui::End();

	}

}