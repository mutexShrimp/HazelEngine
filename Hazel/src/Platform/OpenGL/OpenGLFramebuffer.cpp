#include "hzpch.h"
#include "OpenGLFramebuffer.h"

#include <glad/glad.h>

namespace Hazel
{
    OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec)
        : m_Specification(spec)
    {
        Invalidate();
        
    }

    OpenGLFramebuffer::~OpenGLFramebuffer()
    {
        glDeleteFramebuffers(1, &m_RendererID);
    }

    void OpenGLFramebuffer::Invalidate()
    {
        glCreateFramebuffers(1, &m_RendererID);

        glCreateTextures(GL_TEXTURE_2D, 1, &m_ColorAttachment);
        
    }
}
