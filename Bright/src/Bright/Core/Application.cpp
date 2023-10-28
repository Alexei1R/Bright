#include "brpch.h"
#include "Application.h"
#include "glad/glad.h"

#include "include/imgui.h"
#include "Platform/Renderer/Model.h"

namespace Bright {
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		s_Instance = (Application*)this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));



		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		model.loadModel("C:/Users/alexe/OneDrive/Desktop/Code/Bright/ASSETS/Model/car.fbx");
		
	}


	Application::~Application() 
	{
		delete m_Window;
	}


	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		//layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		//layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;

			if (e.GetEventType() == Bright::EventType::KeyPressed) {
				// Cast the event to KeyPressedEvent
				Bright::KeyPressedEvent& keyPressedEvent = dynamic_cast<Bright::KeyPressedEvent&>(e);

				// Access the key code from the event
				int keyCode = keyPressedEvent.GetKeyCode();

				//BR_INFO("Key Pressed: {0}", keyCode);
			}


			if (e.GetEventType() == Bright::EventType::MouseMoved) {
				// Cast the event to KeyPressedEvent
				Bright::MouseMovedEvent& maouseMovedEvent = dynamic_cast<Bright::MouseMovedEvent&>(e);

				// Access the key code from the event
				int x = maouseMovedEvent.GetX();
				int y = maouseMovedEvent.GetY();

				//BR_INFO("Mouse x{0} : y{1}", x,y);
			}
		}
	}

	void Application::Run()
	{
		while (isRunnig)
		{
			glClearColor(0.1, 0.6, 0.3, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			{
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();




			m_Window->OnUpdate();

		}
	}













	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		isRunnig = false;
		return true;
	}
}