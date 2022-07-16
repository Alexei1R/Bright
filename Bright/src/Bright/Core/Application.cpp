#include "brpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>


namespace Bright
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)


	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Bright::Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	
	}

	void Application::OnEvent(Event& e)
	{	
		//if (e.GetEventType() == EventType::MouseMoved)
		//{
		//	BR_CRITICAL("{0}",e.ToString())
		//}

		EventDispatcher dispather(e);
		dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCloseEvent));

		BR_INFO("{0}",e)
	}


	Application::~Application()
	{}

	void Application::Run()
	{
		while (m_Running)
		{
			
			glClearColor(0.5, 1.0, 1.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);






			m_Window->OnUpdate();

		}
	}


















	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}



}