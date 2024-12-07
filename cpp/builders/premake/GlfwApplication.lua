workspace("GlfwApplication")
    configurations({ "Debug", "Release" })

    project("GlfwApplication")
        kind("ConsoleApp")
        language("C++")
        -- current project cpp version
        -- cppdialect "C++20"

        targetdir("bin/%{cfg.system}/%{cfg.buildcfg}")

        files({ "**.hpp", "**.h", "**.cpp", "**.c" })

        links({ "glm", "GL", "glfw", "X11", "freetype", "assimp", "Xrandr", "Xi", "dl" })

        filter("configurations:Debug")
            defines({ "DEBUG" })
            symbols("On")

        filter("configurations:Release")
            defines({ "NDEBUG" })
            optimize("On")
