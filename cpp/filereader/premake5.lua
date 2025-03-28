workspace("Reader")
    configurations({ "Debug", "Release" })

    project("App")
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
