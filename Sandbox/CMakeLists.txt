project(Sandbox)

file(GLOB SANDBOX_SOURCES 
    "src/*.cpp"
    "src/*.h"
)

add_executable(Sandbox ${SANDBOX_SOURCES})

target_link_libraries(Sandbox 
    PRIVATE 
        Hazel
)

target_include_directories(Sandbox 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/Hazel/src 
        ${CMAKE_SOURCE_DIR}/Hazel/vendor/spdlog/include
)

set_target_properties(Sandbox PROPERTIES
    OUTPUT_NAME "Sandbox"
)
