#pragma once
#include "Bright/Core/macros.h"
#include "Bright/Core/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Bright {

	class OpenGLWindow : public Window {

	public:
		OpenGLWindow(const WindowSpecs& spec);
		~OpenGLWindow();


		void OnUpdate()override;

		inline  unsigned int GetWidth()const override {return m_Data.Width;};
		inline unsigned int GetHeight()const override { return m_Data.Height; };

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override { return m_Window; };

		void SetCallbacks();
	private:
		virtual void Init(const WindowSpecs& specs);
		virtual void Shutdown();

	private:
		
		GLFWwindow* m_Window;


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;


	};



}