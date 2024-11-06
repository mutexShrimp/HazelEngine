#include "hzpch.h"
#include "OrthographicCameraController.h"

#include "Hazel/Input.h"
#include "Hazel/KeyCodes.h"

namespace Hazel
{
    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
        :   m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel),
            m_Rotation(rotation)
    {
        
    }

    void OrthographicCameraController::OnUpdate(Timestep ts)
    {
        if (Input::IsKeyPressed(HZ_KEY_A))
        {
            m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(HZ_KEY_D))
        {
            m_CameraPosition.x += m_CameraTranslationSpeed * ts;
        }

        if (Input::IsKeyPressed(HZ_KEY_W))
        {
            m_CameraPosition.y += m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(HZ_KEY_S))
        {
            m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
        }

        if (m_Rotation)
        {
            if (Input::IsKeyPressed(HZ_KEY_Q))
            {
                m_CameraRotation -= m_CameraRotationSpeed * ts;
            }

            if (Input::IsKeyPressed(HZ_KEY_E))
            {
                m_CameraRotation += m_CameraRotationSpeed * ts;
            }
        }
    }

    void OrthographicCameraController::OnEvent(Event& e)
    {
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
    {
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
    {
    }
}
