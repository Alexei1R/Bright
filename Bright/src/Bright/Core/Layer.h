#pragma once
#include "brpch.h"
#include "Bright/Event/Event.h"

namespace Bright
{

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}


		virtual void Begin(){}
		virtual void End(){}

		inline const std::string& GetName() { return m_Name; }
	private:
		std::string m_Name;
	};

}