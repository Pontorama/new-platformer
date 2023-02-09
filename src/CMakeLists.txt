set(HEADER_LIST 
    "${monke_platformer_SOURCE_DIR}/include/GameManager.h"
    "${monke_platformer_SOURCE_DIR}/include/Camera.h"
    "${monke_platformer_SOURCE_DIR}/include/core/GameObject.h"
    "${monke_platformer_SOURCE_DIR}/include/core/Hitbox.h"
    "${monke_platformer_SOURCE_DIR}/include/math/Vector.h"
    )

# Create an automatic library
add_library(game_core 
            GameManager.cpp 
            Camera.cpp 
            core/GameObject.cpp
            core/Hitbox.cpp
            math/Vector.cpp
            ${HEADER_LIST}
            )
# Include header files
target_include_directories(game_core PUBLIC ../include)
# Link required libraries
target_link_libraries(game_core PRIVATE SDL2)
# Use at least c++11
target_compile_features(game_core PUBLIC cxx_std_11)
