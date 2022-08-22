workspace "Bright"
	architecture "x64"
	startproject "Bright-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Bright/vendor/GLFW/include"
IncludeDir["Glad"] = "Bright/vendor/Glad/include"
IncludeDir["ImGui"] = "Bright/vendor/imgui"
IncludeDir["glm"] = "Bright/vendor/glm"
IncludeDir["stb_image"] = "Bright/vendor/stb_image"

group "Dependencies"
	include "Bright/vendor/GLFW"
	include "Bright/vendor/Glad"
	include "Bright/vendor/imgui"

group ""





------------------------------
-----  Bright lib-------------
------------------------------
project "Bright"
	location "Bright"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brpch.h"
	pchsource "Bright/src/brpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"










---------------------------------
------- Editor ------------------
---------------------------------

project "Bright-Editor"
	location "Bright-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Bright/vendor/spdlog/include",
		"Bright/src",
		"Bright/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"Bright"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"






--------------------------------
------ Game --------------------
--------------------------------
--
--		project "Sandbox"
--	location "Sandbox"
--	kind "ConsoleApp"
--	language "C++"
--	cppdialect "C++17"
--	staticruntime "on"
--
--	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
--	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
--
--	files
--	{
--		"%{prj.name}/src/**.h",
--		"%{prj.name}/src/**.cpp"
--	}
--
--	includedirs
--	{
--		"Bright/vendor/spdlog/include",
--		"Bright/src",
--		"Bright/vendor",
--		"%{IncludeDir.glm}"
--	}
--
--	links
--	{
--		"Bright"
--	}
--
--	filter "system:windows"
--		systemversion "latest"
--
--		defines
--		{
--		}
--
--	filter "configurations:Debug"
--		defines "BR_DEBUG"
--		runtime "Debug"
--		symbols "on"
--
--	filter "configurations:Release"
--		defines "BR_RELEASE"
--		runtime "Release"
--		optimize "on"
--
--	filter "configurations:Dist"
--		defines "BR_DIST"
--		runtime "Release"
--		optimize "on"