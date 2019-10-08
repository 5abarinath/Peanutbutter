workspace "Peanutbutter"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Peanutbutter"
    location "Peanutbutter"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "PB_WINDOWS_PLATFORM",
        "PB_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
    defines "PB_DEBUG"
    symbols "On"

    filter "configurations:Release"
    defines "PB_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "PB_DIST"
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
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Peanutbutter/vendor/spdlog/include",
        "Peanutbutter/src"
    }

    links
    {
        "Peanutbutter"
    }

    filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "PB_WINDOWS_PLATFORM"
    }

    filter "configurations:Debug"
    defines "PB_DEBUG"
    symbols "On"

    filter "configurations:Release"
    defines "PB_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "PB_DIST"
    optimize "On"