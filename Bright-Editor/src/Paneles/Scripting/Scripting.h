#pragma once
#include "Bright.h"
#include "TextEditor.h"




namespace Bright {

	class Scripting {
	public:
		Scripting();

		void GetDrawData();




	private:
		const int m_ButtonWidth = 55;

		TextEditor m_TextEditor;

	private:
		GLuint m_StartTexture = 0;
		GLuint m_ImportTexture = 0;
		GLuint m_OpenTexture = 0;
		GLuint m_SaveTexture = 0;


	};




}

