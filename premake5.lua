---解决方案
workspace "Neko"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

---定义路径
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

---neko项目
project "Neko"
	location "Neko"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir .."/%{prj.name}")
	objdir("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "c++latest"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NEKO_BUILD_DLL",
			"NEKO_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations: Debug"
			defines "NEKO_DEBUG"
			symbols "On"

		filter "configurations: Release"
			defines "NEKO_RELEASE"
			optimize "On"

		filter "configurations: Dist"
			defines "NEKO_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/".. outputdir .."/%{prj.name}")
	objdir("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Neko/vendor/spdlog/include",
		"Neko/src"
	}

	links
	{
		"Neko"
	}

	filter "system:windows"
	cppdialect "c++latest"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"NEKO_PLATFORM_WINDOWS"
	}

	filter "configurations: Debug"
		defines "NEKO_DEBUG"
		symbols "On"

	filter "configurations: Release"
		defines "NEKO_RELEASE"
		optimize "On"

	filter "configurations: Dist"
		defines "NEKO_DIST"
		optimize "On"