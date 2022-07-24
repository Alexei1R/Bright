#include "brpch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Bright/Core/Application.h"

namespace Bright
{   
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPresedImpl(int keyCode)
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApp().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keyCode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    bool WindowsInput::IsMousePresedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApp().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    std::pair<double, double> WindowsInput::GetMousePosImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::GetApp().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window,&xpos,&ypos);

        
        return {xpos,ypos};
    }
    double WindowsInput::GetMouseXImpl()
    {
        auto [x, y] = GetMousePosImpl();
        return x;
    }
    double WindowsInput::GetMouseYImpl()
    {
        auto [x, y] = GetMousePosImpl();
        return y;
    }
}