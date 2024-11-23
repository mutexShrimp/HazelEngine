#pragma once

#include "Hazel/Renderer/Camera.h"

namespace Hazel
{
    class SceneCamera : public Camera
    {
    public:
        enum class ProjectionType { Perspective = 0, Orthographic = 1 };
        
    public:
        SceneCamera();
        virtual ~SceneCamera() = default;

        float GetOrthographicSize() const { return m_OrthographicSize; }
        ProjectionType GetProjectionType() const { return m_ProjectionType; }
        float GetOrthographicNearClip() const { return m_OrthographicNear; }
        float GetOrthographicFarClip() const { return m_OrthographicFar; }
        
        void SetOrthographic(float size, float nearClip, float farClip);
        void SetViewportSize(uint32_t width, uint32_t height);
        void SetOrthographicSize(float size) { m_OrthographicSize = size;  RecalculateProjection(); }
        void SetProjectionType(ProjectionType type) { m_ProjectionType = type; }
        void SetOrthographicNearClip(float nearClip) { m_OrthographicNear = nearClip; }
        void SetOrthographicFarClip(float farClip) { m_OrthographicFar = farClip; }
        
    private:
        void RecalculateProjection();
        
    private:
        ProjectionType m_ProjectionType = ProjectionType::Orthographic;
        
        float m_OrthographicSize = 10.0f;
        float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;

        float m_AspectRatio = 1.0f;
        
    };
}
