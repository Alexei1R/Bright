#include "brpch.h"
#include "Application.h"
#include "glad/glad.h"

#include "include/imgui.h"

namespace Bright {
	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		s_Instance = (Application*)this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));



		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		camera = new Core::Camera(glm::vec3(0.0, 0.0, 3.0));


		model = new Core::Model;


		model->loadModel("C:/Users/alexe/OneDrive/Desktop/Code/Bright/ASSETS/Model/cube.obj");
		

		shader = new Core::Shader("C:/Users/alexe/OneDrive/Desktop/Code/Bright/ASSETS/Shader/vs.glsl", "C:/Users/alexe/OneDrive/Desktop/Code/Bright/ASSETS/Shader/fs.glsl");
		transform = new Core::Transform(*shader);
		transform->rotateRadians(-90, glm::vec3(1.0, 0.0, 0.0));
		//transform->scale(glm::vec3(0.01, 0.01, 0.01));
		
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
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			/*m_ImGuiLayer->Begin();
			{
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();*/


			transform->UpdateCam(camera->GetViewMatrix(), camera->GetCameraPos(), camera->GetCameraFront(), m_Window->GetWidth(), m_Window->GetHeight());
			camera->Update();

			shader->Bind();
			model->Draw(*shader);




			m_Window->OnUpdate();

		}
	}













	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		isRunnig = false;
		return true;
	}
}