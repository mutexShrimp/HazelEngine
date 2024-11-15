#pragma once

#include "Base.h"

#include "Window.h"
#include "Hazel/Core/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"

#include "Hazel/Core/Timestep.h"

#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application(const std::string& name = "Game Engine");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		
	private:
		static Application* s_Instance;
		
	};

	// To be defined in Client
	Application* CreateApplication();

}
