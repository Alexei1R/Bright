#pragma once
#include "Bright.h"
#include "Bright/Core/Window.h"
#include "Bright/Core/Layers/Layer.h"
#include "Bright/Core/Layers/LayerStack.h"
#include "Bright/ImGui/ImGuiLayer.h"
#include "Platform/Renderer/Model.h"
#include "Platform/Renderer/Shader.h"
#include "Platform/Renderer/Camera.h"
#include "Platform/Renderer/Transform.h"


namespace Bright {
	class Application {
	public:

		Application();
		~Application();


		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline static Application& GetApp() { return *s_Instance; }
		inline  Window& GetWindow() { return *m_Window; }
	public:
		void OnEvent(Event& e);


	public:
		static Application* s_Instance;

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		bool isRunnig = true;


	private:
		Window* m_Window;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		Core::Model* model;
		Core::Shader* shader;
		Core::Camera* camera;
		Core::Transform* transform;
		


	};
}