# General project info
cmake_minimum_required(VERSION 3.13)
project(monke_platformer VERSION 0.1 DESCRIPTION "Monke!" LANGUAGES CXX)

# Find libraries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Add files to compile
add_subdirectory(src)
# Add main
add_executable(monke_platformer main.cpp)
target_link_libraries(monke_platformer ${SDL2_LIBRARIES})
target_include_directories(monke_platformer PUBLIC include)
