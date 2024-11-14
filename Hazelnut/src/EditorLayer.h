#pragma once

#include "Hazel.h"

namespace Hazel
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        ~EditorLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
        void OnEvent(Event& e) override;

    private:
        OrthographicCameraController m_CameraController;
    
        Ref<Shader> m_FlatColorShader;
        Ref<VertexArray> m_SquareVA;
        Ref<Framebuffer> m_Framebuffer;
    
        Ref<Texture2D> m_CheckerboardTexture;

        glm::vec2 m_ViewportSize;
        
        glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

    };
}