cmake_minimum_required(VERSION 3.10)
project(project_name)
add_compile_options(-std=c++11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
