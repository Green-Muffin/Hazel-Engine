# 引擎核心库
project(Hazel)

# 收集源文件
file(GLOB_RECURSE HAZEL_SOURCES 
    "src/*.cpp"
    "src/*.h"
)


add_library(Hazel SHARED 
    ${HAZEL_SOURCES}
)

target_include_directories(Hazel 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

target_compile_definitions(Hazel 
    PUBLIC 
        HZ_PLATFORM_MACOS
        HZ_BUILD_DLL
        $<$<CONFIG:Debug>:HZ_DEBUG>
        $<$<CONFIG:Release>:HZ_RELEASE>
)

set_target_properties(Hazel PROPERTIES
    OUTPUT_NAME "Hazel"
)