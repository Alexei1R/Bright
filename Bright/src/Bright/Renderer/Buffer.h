#pragma once

namespace Bright {
	/////////////////////////////////
	///=======Buffer Layout====//////
	/////////////////////////////////

	enum class ShaderDataType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Int, Int2, Int3, Int4,
		Mat3, Mat4,
		Bool

	};
	static uint32_t ShaderDataTypeToOpenGLType(ShaderDataType type) {
		switch (type)
		{
		case Bright::ShaderDataType::None:
			return 0x1406;
		case Bright::ShaderDataType::Float:
			return 0x1406;
		case Bright::ShaderDataType::Float2:
			return 0x1406;
		case Bright::ShaderDataType::Float3:
			return 0x1406;
		case Bright::ShaderDataType::Float4:
			return 0x1406;
		case Bright::ShaderDataType::Mat3:
			return 0x1406;
		case Bright::ShaderDataType::Mat4:
			return 0x1406;
		

		case Bright::ShaderDataType::Int:
			return 0x1404;
		case Bright::ShaderDataType::Int2:
			return 0x1404;
		case Bright::ShaderDataType::Int3:
			return 0x1404;
		case Bright::ShaderDataType::Int4:
			return 0x1404;
		
		case Bright::ShaderDataType::Bool:
			return 0x8B56;
		}
	}
	static uint32_t ShaderDataTypeSize(ShaderDataType type) {
		switch (type)
		{
		case Bright::ShaderDataType::None:
			return 0;
		case Bright::ShaderDataType::Float:
			return 4;
		case Bright::ShaderDataType::Float2:
			return 8;
		case Bright::ShaderDataType::Float3:
			return 12;
		case Bright::ShaderDataType::Float4:
			return 16;
		case Bright::ShaderDataType::Int:
			return 4;
		case Bright::ShaderDataType::Int2:
			return 8;
		case Bright::ShaderDataType::Int3:
			return 12;
		case Bright::ShaderDataType::Int4:
			return 16;
		case Bright::ShaderDataType::Mat3:
			return 36;
		case Bright::ShaderDataType::Mat4:
			return 64;
		case Bright::ShaderDataType::Bool:
			return 1;

		}

		BR_ASSERT(0, "Unknown Shader Type")
			return 0;
	}

	struct BufferElements {
		std::string Name;
		ShaderDataType Type;
		uint32_t Offset;
		uint32_t Size;
		BufferElements() {}
		BufferElements(const std::string& name, ShaderDataType type)
			:Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0)
		{
		}


		uint32_t GetConponetCount()
		{
			switch (Type)
			{
			case Bright::ShaderDataType::None:
				return 0;
			case Bright::ShaderDataType::Float:
				return 1;
			case Bright::ShaderDataType::Float2:
				return 2;
			case Bright::ShaderDataType::Float3:
				return 3;
			case Bright::ShaderDataType::Float4:
				return 4;
			case Bright::ShaderDataType::Int:
				return 1;
			case Bright::ShaderDataType::Int2:
				return 2;
			case Bright::ShaderDataType::Int3:
				return 3;
			case Bright::ShaderDataType::Int4:
				return 4;
			case Bright::ShaderDataType::Mat3:
				return 3 * 3;
			case Bright::ShaderDataType::Mat4:
				return 4 * 4;
			case Bright::ShaderDataType::Bool:
				return 1;

			}
		}
	};


	class BufferLayout {
	public:
		BufferLayout() {}
		BufferLayout(std::initializer_list<BufferElements>& element)
			:m_Elements(element)
		{
			CalculateOffsetAndStride();
		};

		uint32_t GetStride() { return m_Stride; }
		std::vector<BufferElements>& GetElements() { return m_Elements; };
		std::vector<BufferElements>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElements>::iterator end() { return m_Elements.end(); }

		std::vector<BufferElements>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElements>::const_iterator end()   const { return m_Elements.end(); }


	private:
		void CalculateOffsetAndStride() {
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements) {
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		uint32_t m_Stride;
		std::vector<BufferElements> m_Elements;


	};
















	/////////////////////////////////
	///=============Vertex=====//////
	/////////////////////////////////
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}



		virtual void Bind() = 0;
		virtual void UnBind() = 0;
		virtual BufferLayout& GetLayout() = 0;
		virtual void SetLayout(BufferLayout& layout) = 0;

		static VertexBuffer* Create(float* vertices);
	};
	/////////////////////////////////
	///=============Index======//////
	/////////////////////////////////
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual uint32_t GetCount() = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t count);

	};


}