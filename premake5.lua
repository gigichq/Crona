workspace "Crona"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Crona/vendor/GLFW/include"
IncludeDir["GLAD"] = "Crona/vendor/GLAD/include"
IncludeDir["Imgui"] = "Crona/vendor/imgui"

include "Crona/vendor/GLFW"
include "Crona/vendor/GLAD"
include "Crona/vendor/imgui"

project "Crona"
	location "Crona"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "capch.h"
	pchsource "Crona/src/capch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.Imgui}"
	}
	
	links 
	{ 
		"GLFW",
		"GLAD",
		"Imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"CRONA_BUILD_DLL",
			"CA_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CA_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Crona/vendor/spdlog/include",
		"Crona/src",
		"Crona/src/crona",
	}

	links
	{
		"Crona"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"CA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CA_DIST"
		optimize "On"