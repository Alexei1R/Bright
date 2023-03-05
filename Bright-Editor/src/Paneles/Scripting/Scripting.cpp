#include "brpch.h"
#include "Scripting.h"



namespace Bright {


	int plot(lua_State* L)
	{
		// Get the table argument from the Lua stack
		luaL_checktype(L, 1, LUA_TTABLE);

		// Loop through the table and print each element
		int table_len = luaL_len(L, 1);
		for (int i = 1; i <= table_len; i++)
		{
			lua_pushinteger(L, i);
			lua_gettable(L, 1);
			float data = (float)lua_tonumber(L, -1);
			std::cout << data << std::endl;
			lua_pop(L, 1);
		}

		return 0;
	}


	Scripting::Scripting(SREngine* script)
		:m_Script(script)
	{
		m_TextEditor.SetShowWhitespaces(false);
		m_TextEditor.SetReadOnly(false);
		m_TextEditor.SetPalette(TextEditor::GetDarkPalette());
		m_TextEditor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());


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
		ImGui::Begin("Script", false, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
		ImVec2 m_WSize = ImGui::GetWindowSize();

		ImGui::Columns(2);
		ImGui::SetColumnOffset(1, (float)m_ButtonWidth);

		{//Left side
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.25, 0.25, 0.25, 0.0));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.2f, 0.2f, 0.7f));

			ImGui::Spacing();

			if (ImGui::ImageButton((void*)(intptr_t)m_StartTexture, ImVec2(25, 25), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), 1, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), ImVec4(1.0f, 1.0f, 1.0f, 1.0f))) {


				m_Script->Restart();
				m_Script->AddScriptFunction("plot", plot);
				std::thread th(
					[&]()
					{
						std::string data = m_TextEditor.GetText();
						if (data.empty()) { return; }
						else {
							try {
								std::string err = m_Script->RunScript(data.c_str());
								if (!err.empty()) {
									BR_CRITICAL("{0}", err);
									TextEditor::ErrorMarkers markers;
									//BR_CRITICAL("\n{0}", e.line);
									//BR_CRITICAL("\n{0}", e.error);
									//std::pair<int, std::string> errors((int)(e.line), (std::string)e.error);
									markers.insert(ParseError(err));
									//ParseError(err);
									m_TextEditor.SetErrorMarkers(markers);
								}
							}
							catch (const std::exception& e) {
								BR_CRITICAL("{0}", e.what());

							}

						}



					}
				);
				th.detach();

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



			m_TextEditor.Render("Scripting", ImVec2(m_WSize.x - 108, (m_WSize.y - m_ButtonWidth) - 10));


		}


		//END WINDOW
		ImGui::End();

	}

	





	std::pair<int, std::string> Scripting::ParseError(std::string error) {
	
		int num;

		std::regex re(":\\d+:");

		std::smatch match;
		if (std::regex_search(error, match, re)) {
			std::string match_str = match[0].str();
			num = stoi(match_str.substr(1, match_str.size() - 2));
			std::cout << "Line number: " << num << std::endl;
		}
		else {
			num = 0;
			std::cout << "No match found" << std::endl;
		}
		std::pair<int, std::string> pair(num -1 ,error);

		return pair;
	}

}