#include "brpch.h"
#include "WindowsWindow.h"

#include "Bright/Event/ApplicationEvent.h"
#include "Bright/Event/KeyEvent.h"
#include "Bright/Event/MouseEvent.h"


namespace Bright
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		BR_ERROR("GLFW ERROR {0}: {1}",error,description)
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	Bright::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	Bright::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}






	void Bright::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;


		BR_INFO("Creating Window {0} , ({1}:{2})", props.Title, props.Width, props.Height)

			if (!s_GLFWInitialized)
			{
				//Initialize GLFW
				int success = glfwInit();
				BR_ASSERT(success, "Could not intialize GLFW!");
				glfwSetErrorCallback(GLFWErrorCallback);
				s_GLFWInitialized = true;
			}


		m_Window = glfwCreateWindow(int(props.Width), int(props.Height), m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BR_ASSERT(status,"Glad don't init")

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);





		//set event callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}

				}
			});




		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)x, (float)y);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)x, (float)y);
				data.EventCallback(event);
			});



















	}



	void Bright::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}



	void Bright::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}






	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}