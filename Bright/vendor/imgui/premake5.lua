project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{

		"include/**.h",
		"include/**.cpp",
		
		--"inlude/imconfig.h",
		--"inlude/imgui.h",
		--"inlude/imgui.cpp",
		--"inlude/imgui_demo.cpp",
		--"inlude/imgui_draw.cpp",
		--"inlude/imgui_impl_opengl3.cpp",
		--"inlude/imgui_impl_opengl3.h",
		--"inlude/imgui_impl_opengl3_loader.h",
		--"inlude/imgui_internal.h",
		--"inlude/imgui_tables.cpp",
		--"inlude/imgui_widgets.cpp",
		--"inlude/imstb_rectpack.h",
		--"inlude/imstb_textedit.h",
		--"inlude/imstb_truetype.h",
		--"inlude/imgui_impl_glfw.h",
		--"inlude/imgui_impl_glfw.cpp",
		





	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"