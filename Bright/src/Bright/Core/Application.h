#pragma once
#include "brpch.h"
#include "Bright/Core/Window.h"
#include "Bright/Event/ApplicationEvent.h"
#include "Bright/Core/LayerStack.h"
#include "Bright/ImGui/ImGuiLayer.h"

namespace Bright
{
	class Application
	{

	public:
		Application();
		virtual	~Application();

		void Run();
	


		void OnEvent(Event& e);


		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetApp() { return *s_Application; }

	private:
		Layer* m_ImGuiLayer;
		std::unique_ptr<Bright::Window> m_Window;
		LayerStack m_LayerStack;

		
	private:
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool m_Running = true;
		static Application* s_Application;

	};

	Application* CreateApplication();

}