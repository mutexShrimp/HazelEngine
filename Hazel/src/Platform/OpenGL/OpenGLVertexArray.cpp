#include "hzpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Hazel
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::None: return GL_NONE;
        case ShaderDataType::Float: return GL_FLOAT;
        case ShaderDataType::Float2: return GL_FLOAT;
        case ShaderDataType::Float3: return GL_FLOAT;
        case ShaderDataType::Float4: return GL_FLOAT;
        case ShaderDataType::Mat3: return GL_FLOAT;
        case ShaderDataType::Mat4: return GL_FLOAT;
        case ShaderDataType::Int: return GL_INT;
        case ShaderDataType::Int2: return GL_INT;
        case ShaderDataType::Int3: return GL_INT;
        case ShaderDataType::Int4: return GL_INT;
        case ShaderDataType::Bool: return GL_BOOL;
        }
        HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return GL_NONE;
    }
    
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
    {
        HZ_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");
        
        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();
    	
        const auto& layout = vertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
	        switch (element.Type)
	        {
	        case ShaderDataType::Float:
	        case ShaderDataType::Float2:
	        case ShaderDataType::Float3:
	        case ShaderDataType::Float4:
		        {
	        		glEnableVertexAttribArray(m_VertexBufferIndex);
	        		glVertexAttribPointer(
	        			m_VertexBufferIndex,
	        			element.GetComponentCount(),
	        			ShaderDataTypeToOpenGLBaseType(element.Type),
						element.Normalized ? GL_TRUE : GL_FALSE,
						layout.GetStride(),
						(const void*)element.Offset
						);
	        		m_VertexBufferIndex++;
	        		break;
		        }
	        case ShaderDataType::Int:
			case ShaderDataType::Int2:
			case ShaderDataType::Int3:
			case ShaderDataType::Int4:
			case ShaderDataType::Bool:
		        {
	        		glEnableVertexAttribArray(m_VertexBufferIndex);
	        		glVertexAttribIPointer(
						m_VertexBufferIndex,
						element.GetComponentCount(),
						ShaderDataTypeToOpenGLBaseType(element.Type),
						layout.GetStride(),
						(const void*)element.Offset
						);
	        		m_VertexBufferIndex++;
	        		break;
		        }
	        case ShaderDataType::Mat3:
	        case ShaderDataType::Mat4:
		        {
	        		uint8_t count = element.GetComponentCount();
	        		for (uint8_t i = 0; i < count; i++)
	        		{
	        			glEnableVertexAttribArray(m_VertexBufferIndex);
	        			glVertexAttribPointer(
							m_VertexBufferIndex,
							count,
							ShaderDataTypeToOpenGLBaseType(element.Type),
							element.Normalized ? GL_TRUE : GL_FALSE,
							layout.GetStride(),
							(const void*)(element.Offset + sizeof(float) * count * i)
							);
	        			//如果 divisor 设置为 0，那么对应的顶点属性值会在每个顶点之间更新一次。
	        			//如果 divisor 设置为非零值，那么属性值会在每 divisor 个实例之间更新一次。这意味着，如果一个属性的 divisor 被设置为 1，那么每个实例都会使用该属性数组中的新值
	        			glVertexAttribDivisor(m_VertexBufferIndex, 1);
	        			m_VertexBufferIndex++;
	        		}
	        		break;
		        }
	        default: HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
	        }
        }

        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
        
    }
}
