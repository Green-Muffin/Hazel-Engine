project(Hazel)

option(HZ_ENABLE_PCH "Enable precompiled headers for Hazel" ON)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/GLFW)

file(GLOB_RECURSE HAZEL_SOURCES 
    "src/*.cpp"
    "src/*.h"
)


add_library(Hazel SHARED 
    ${HAZEL_SOURCES}
)

if (HZ_ENABLE_PCH)
    if (CMAKE_VERSION VERSION_LESS 3.16)
        message(WARNING "HZ_ENABLE_PCH=ON. CMake version is not recommand. The version is : ${CMAKE_VERSION}")
    else()
        target_precompile_headers(Hazel PRIVATE src/hzpch.h)
        message(STATUS "Hazel: Precompiled headers enabled (hzpch.h)")
    endif()
endif()

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

target_link_libraries(Hazel PRIVATE glfw)