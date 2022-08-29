#include "brpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Platform/Window/OpenGLBuffer.h"


namespace Bright {
    VertexBuffer* Bright::VertexBuffer::Create(float* vertices)
    {
        switch (Renderer::GetAPI()) {
        case RendererAPI::None:
            BR_ASSERT(0, "No Api Specified")
                return 0;

        case RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices);

        }
    }
    
    IndexBuffer* Bright::IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetAPI()) {
        case RendererAPI::None:
            BR_ASSERT(0, "No Api Specified")
                return 0;

        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(indices,count);

        }
    }

    
}