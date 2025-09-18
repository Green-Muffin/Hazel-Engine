cmake_minimum_required(VERSION 3.15)

project(HazelEngine VERSION 0.1.0 LANGUAGES CXX)

if (CMAKE_SIZEOF_VOID_P EQUAL 4)
	message(FATAL_ERROR "32-bit builds are not supported by this project. Please use a 64-bit toolchain.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib") 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(Hazel)
add_subdirectory(Sandbox)


