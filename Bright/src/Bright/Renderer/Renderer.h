#pragma once

namespace Bright {

	enum class RendererAPI
	{

		None =0,
		OpenGL,
		Vulcan,
	};
	

	class Renderer {

	public:

		inline static RendererAPI GetAPI() { return s_RendererAPI; }


	private:
		static RendererAPI s_RendererAPI;


	};

}
