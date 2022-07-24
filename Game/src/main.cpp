#include "Bright.h"
#include "imgui/imgui.h"


class ExampleLayer : public Bright::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
			//BR_TRACE("Window update!");
	}


	void OnAttach()override
	{

	}


	void OnImGuiRender()override
	{

		
		ImGui::Begin("Example");
		int a = ImGui::GetTime();
		int b =10;

		ImGui::Text("alexei %i", a);
		ImGui::SliderInt("Example",&b,1,100);
		ImGui::Text("alexei %i", b);
		ImGui::End();
		
	}




	void OnEvent(Bright::Event& event) override
	{
		if (event.GetEventType() == Bright::EventType::KeyPressed)
		{
			Bright::KeyPressedEvent& e = (Bright::KeyPressedEvent&)event;
			BR_CRITICAL("{0}", (char)e.GetKeyCode())
		}
		if(event.GetEventType() == Bright::EventType::MouseMoved)
		{
			Bright::MouseMovedEvent& e = (Bright::MouseMovedEvent&)event;
			//BR_INFO("{0} : {1}",e.GetX(),e.GetY())
		}
	}

};

class Game : public Bright::Application
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
	}

	~Game()
	{

	}



};


Bright::Application* Bright::CreateApplication()
{
	return new Game();
}