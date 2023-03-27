workspace "Hazel"        -- 解决方案名称
    architecture "x64"   -- 相当于platform
    
    configurations
    {
        "Debug",
        "Release",       -- 禁用一些优化，但是还是有日志信息
        "Dist"
    }
-- 输出路径变量：类似于 debug-windows-x64    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"   

project "Hazel"         -- 项目名称
    location "Hazel"
    kind "SharedLib" -- DLL
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- lua的字符串拼接方式
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "hzpch.h"  -- 等同于在项目设置中 设置预编译头文件为 use，并指定头文件为hzpch.h
    pchsource "Hazel/src/hzpch.cpp" -- 等同于在hzpch.cpp的设置中 预编译头为 create

    files                                   -- 包含项目下所有的.h .cpp文件
    {
        "%{prj.name}/src/**.h",    
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows" --对特定的系统(windows\OS..)、配置(Debug/Release)、平台(x64 x86)的项目属性
        cppdialect "C++17"  --C++特性版本
        staticruntime "On"  --需要动态链接库
        systemversion "latest"    -- windowsSKD版本,.x表示win10任何版本，11.x则表示win11

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL"
        }

        postbuildcommands
        {
            -- 拷贝本项目的输出文件中的dll到指定文件夹中，第一个内置变量就是本项目输出的目标文件（用相对路径表示）
            -- ../bin/" .. outputDir .. "/Sandbox" 表示复制到本项目路径的的上级路径（解决方案路径）中的bin中的.....
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
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
        "Hazel/vendor/spdlog/include",
        "Hazel/src"
    }

    links        --链接项目
    {
        "Hazel"
    }

    filter "system:windows" 
        cppdialect "C++17" 
        staticruntime "On"  
        systemversion "latest" 

        defines
        {
            "HZ_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On" 

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"