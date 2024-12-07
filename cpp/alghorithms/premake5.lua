workspace("Application")
    configurations({ "Debug", "Release" })

    project("Application")
        kind("ConsoleApp")
        language("C++")
        -- current project cpp version
        -- cppdialect "C++20"

        targetdir("bin/%{cfg.system}/%{cfg.buildcfg}")

        files({ "**.hpp", "**.h", "**.cpp", "**.c" })

        links({})

        filter("configurations:Debug")
            defines({ "DEBUG" })
            symbols("On")

        filter("configurations:Release")
            defines({ "NDEBUG" })
            optimize("On")
