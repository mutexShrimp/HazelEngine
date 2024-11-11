#include "SandboxApplication2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SandboxApplication2D::SandboxApplication2D()
	:	Layer("SandboxApplication2D"),
		m_CameraController(1280.0f / 720.0f, true)
{
	
}

void SandboxApplication2D::OnAttach()
{
	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
	
}

void SandboxApplication2D::OnDetach()
{
    Layer::OnDetach();
}

void SandboxApplication2D::OnUpdate(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();
	
    // Update
	{
		HZ_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}
	
    // Render
	{
		HZ_PROFILE_SCOPE("Renderer Prep");
		Hazel::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
		Hazel::RenderCommand::Clear();
	}

	{
		HZ_PROFILE_SCOPE("Renderer Draw");
		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		//Hazel::Renderer2D::DrawRotatedQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, glm::radians(60.0f), {0.8f, 0.2f, 0.3f, 1.0f});
		Hazel::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
		Hazel::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75f}, {0.2f, 0.3f, 0.8f, 1.0f});
		Hazel::Renderer2D::DrawQuad({-5.0f, -5.0f, -0.1f}, {10.5f, 10.5f}, m_CheckerboardTexture, 10.0f); 
		Hazel::Renderer2D::EndScene();
	}
	
}

void SandboxApplication2D::OnImGuiRender()
{
	HZ_PROFILE_FUNCTION();
	
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	
    ImGui::End();
}

void SandboxApplication2D::OnEvent(Hazel::Event& e)
{
    m_CameraController.OnEvent(e);
}
