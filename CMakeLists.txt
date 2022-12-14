# General project info
cmake_minimum_required(VERSION 3.13)
project(monke_platformer VERSION 0.1 DESCRIPTION "Monke!" LANGUAGES CXX)

if(WIN32)
    set(CMAKE_CXX_COMPILER g++)
    set(SDL2_DIR "${CMAKE_CURRENT_LIST_DIR}/dependencies/SDL2/cmake")
    # Includes
    include_directories("${CMAKE_CURRENT_LIST_DIR}/dependencies/SDL2/i686-w64-mingw32/include")
    include_directories("${CMAKE_CURRENT_LIST_DIR}/dependencies/SDL2/x86_64-w64-mingw32/include")
endif()
# Find libraries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Add files to compile
link_directories(src)
add_subdirectory(src)
# Add main
add_executable(monke_platformer main.cpp)
target_link_libraries(monke_platformer game_core)
target_link_libraries(monke_platformer ${SDL2_LIBRARIES})
target_include_directories(monke_platformer PUBLIC ${SDL2_LIBRARIES_DIR})
target_include_directories(monke_platformer PUBLIC include)
