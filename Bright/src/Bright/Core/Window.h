#pragma once
#include "macros.h"


namespace Bright {


	struct WindowSpecs {
		std::string Title;
		unsigned int Width, Height;

		WindowSpecs(const std::string title = "Bright", int width = 1080, int height = 720)
			:Title(title),Width(width),Height(height) {}
	};



	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowSpecs& specs = WindowSpecs());
	};



}