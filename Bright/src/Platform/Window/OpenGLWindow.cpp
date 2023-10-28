#include "brpch.h"
#include "OpenGLWindow.h"



namespace Bright {


	//  Funcion created in Window class
	Window* Window::Create(const WindowSpecs& specs)
	{
		return new OpenGLWindow(specs);
	}


	static void GLFWErrorCallback(int error, const char* description)
	{
		BR_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	OpenGLWindow::OpenGLWindow(const WindowSpecs& spec)
	{
		Init(spec);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		Shutdown();
	}


	// init OpenGl window stuff
	void OpenGLWindow::Init(const WindowSpecs& specs)
	{
		m_Data.Title = specs.Title;
		m_Data.Width = specs.Width;
		m_Data.Height = specs.Height;

		BR_INFO("Creating Window ::  {0}, {1}:{2}", m_Data.Title, m_Data.Width, m_Data.Height)
		int success = glfwInit();
		BR_ASSERT(success, "Could not intialize GLFW!");
		if(success != 1){BR_CRITICAL("!Succes glfw") }
		glfwSetErrorCallback(GLFWErrorCallback);


		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		
		
		
		glfwMakeContextCurrent(m_Window);
		int successGlad = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		
		BR_ASSERT(successGlad, "Could not intialize GLFW!");
		BR_INFO("OpenGL Info:");
		BR_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BR_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BR_INFO("  Version: {0}", glGetString(GL_VERSION));


		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
		SetCallbacks();
		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);
	}
	//close window
	void OpenGLWindow::Shutdown()
	{
		//glfwTerminate();
		//glfwDestroyWindow(m_Window);
	}



	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void OpenGLWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool OpenGLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
	void OpenGLWindow::SetCallbacks() 
	{
	
		// Set GLFW callbacks
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
				Keyboard::keyCallback(window, key, scancode, action, mods);
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
	
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	
				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});
	
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{

				Mouse::mouseButtonCallback(window, button, action, mods);
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
	
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				Mouse::mouseWheelCallback(window, xOffset, yOffset);

				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});
	
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				Mouse::cursorPosCallback(window,xPos,yPos);
				
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}
	

}