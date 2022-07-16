#pragma once
#include "brpch.h"
#include "Bright/Core/Window.h"
#include "Bright/Event/ApplicationEvent.h"

namespace Bright
{
	class Application
	{

	public:
		Application();
		virtual	~Application();

		void Run();
	


		void OnEvent(Event& e);




	private:
		std::unique_ptr<Bright::Window> m_Window;




	private:
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool m_Running = true;

	};

	Application* CreateApplication();

}