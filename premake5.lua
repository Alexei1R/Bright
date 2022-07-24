workspace "Bright"
	architecture "x64"
	language "C++"
	cppdialect "C++17"

	startproject "Game"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


	--outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	outputdir = "-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Bright/vendor/GLFW/include"
	IncludeDir["Glad"] = "Bright/vendor/Glad/include"
	IncludeDir["ImGui"] = "Bright/vendor/imgui"
	IncludeDir["glm"] = "Bright/vendor/glm"

	include "Bright/vendor/GLFW"
	include "Bright/vendor/Glad"
	include "Bright/vendor/imgui"


	---------------------------
	--StaticLib Engine Bright--
	---------------------------
	project "Bright"
		location "Bright"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		------------------
		--------pch-------
		pchheader "brpch.h"
		pchsource "Bright/src/brpch.cpp"
		------------------



		------files------
		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl",
		}

		------defines------
		defines{
			"GLFW_INCLUDE_NONE"
		}

		------includedirs------
		includedirs{
			"%{prj.name}/src/",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}"
		}


		links 
		{ 
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
		}

		------filter------
		filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
			defines "_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "_DIST"
			runtime "Release"
			optimize "on"







	--------------------------------
	--Game make with Bright engine--
	--------------------------------
	project "Game"
		location "Game"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


		------files------
		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
		}

		------defines------
		defines{
			""
		}

		------includedirs------
		includedirs{
			"%{prj.name}/src/",
			"Bright/src/",
			"Bright/vendor/",
			"Bright/vendor/spdlog/include"
		}



		------links------
		links{
			"Bright"
		}



		------filter------
		filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
			defines "_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "_DIST"
			runtime "Release"
			optimize "on"