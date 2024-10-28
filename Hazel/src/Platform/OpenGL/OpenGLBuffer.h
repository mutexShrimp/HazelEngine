#pragma once

#include "Hazel/Renderer/Buffer.h"

namespace Hazel
{
    class OpenGLVertexBuffer: public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        ~OpenGLVertexBuffer() override;

        void Bind() const override;
        void Unbind() const override;

    private:
        uint32_t m_RendererID;
        
    };
}
