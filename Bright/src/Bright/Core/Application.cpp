#include "brpch.h"
#include "Application.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"


namespace Bright
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		s_Application = this;

		m_Window = std::unique_ptr<Window>(Bright::Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	void Application::OnEvent(Event& e)
	{
		//if (e.GetEventType() == EventType::MouseMoved)
		//{
		//	BR_CRITICAL("{0}",e.ToString())
		//}

		EventDispatcher dispather(e);
		dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCloseEvent));

		//BR_INFO("{0}", e)

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}


	Application::~Application()
	{
		delete s_Application;
	}


	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	

	unsigned int VBO;











	void Application::Run()
	{
		while (m_Running)
		{

			glClearColor(0.5, 1.0, 1.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);




			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}


			//auto [x, y] = Input::GetMousePos();
			//BR_TRACE("{0} : {1}",x,y)
			
			

























			bool state = Input::IsKeyPresed(65);
			if (state)
			{
				BR_CRITICAL("Key {0} presed")
			}

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();



			m_Window->OnUpdate();

		}
	}





























	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}



}