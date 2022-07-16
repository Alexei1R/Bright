#pragma once
#include "brpch.h"
#include "Bright/Core/Application.h"
#include "Bright/Core/Log.h"

int main()
{
	Bright::Log::Init();
	Bright::Application* app = Bright::CreateApplication();
	app->Run();
	delete app;

	return 0;
}