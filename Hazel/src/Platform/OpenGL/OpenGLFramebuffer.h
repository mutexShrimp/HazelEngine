#pragma once

#include "Hazel/Renderer/Framebuffer.h"

namespace Hazel
{
    class OpenGLFramebuffer : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();
        
    private:
        uint32_t m_RendererID;
        uint32_t m_ColorAttachment;
        FramebufferSpecification m_Specification;
        
    };
}
