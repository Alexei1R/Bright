#pragma once
#include "Bright/Renderer/Buffer.h"


#include "glad/glad.h"

namespace Bright {
	class OpenGLVertexBuffer: public VertexBuffer
	{

	public:

		OpenGLVertexBuffer(float* vertices);
		~OpenGLVertexBuffer();
		void Bind()override;
		void UnBind()override;

		BufferLayout& GetLayout() override { return m_Layout; };

		void SetLayout(BufferLayout& layout)override { m_Layout = layout; };
	private:
		BufferLayout m_Layout;
		uint32_t m_RendererID;
	};




	class OpenGLIndexBuffer : public IndexBuffer
	{

	public:

		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();
		void Bind()override;
		void UnBind()override;




		virtual uint32_t GetCount() { return m_Count; }

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};

}