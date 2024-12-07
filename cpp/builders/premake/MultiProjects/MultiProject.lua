workspace "Project"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "ProjectMain"

    OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

    libdirs = {
        "bin/" .. OutputDir .. "/",
    }

    group "ProjectMain"
        include "ProjectMain/BuildMain.lua"

    group "OtherProject"
        include "OtherProject/BuildOther.lua"

