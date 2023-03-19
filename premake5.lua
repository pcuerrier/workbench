workspace "workbench"
    configurations { "Debug", "Release" }

project "workbench"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.h", "src/**.hpp", "src/**.c", "src/**.cpp" }

    includedirs { "thirdParty/glfw-3.3.8/include/" }
    libdirs { "thirdParty/glfw-3.3.8/build/src/" }

    links { ":libglfw3.a", "dl", "GL", "GLU", "X11" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Speed"