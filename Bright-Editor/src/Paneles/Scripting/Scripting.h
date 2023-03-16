#pragma once
#include "Bright.h"
#include "ScriptingEngine.h"
#include "TextEditor.h"




namespace Bright {

	

	class Scripting {
	public:
		Scripting(SREngine* script);

		void GetDrawData();

		std::pair<int, std::string> ParseError(std::string error);


	private:
		const int m_ButtonWidth = 55;

		TextEditor m_TextEditor;

	private:
		GLuint m_StartTexture = 0;
		GLuint m_ImportTexture = 0;
		GLuint m_OpenTexture = 0;
		GLuint m_SaveTexture = 0;
		SREngine* m_Script;
		TextEditor::ErrorMarkers markers;

	};




}

