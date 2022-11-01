set(HEADER_LIST 
    "${monke_platformer_SOURCE_DIR}/include/GameManager.h"
    "${monke_platformer_SOURCE_DIR}/include/Camera.h"
    "${monke_platformer_SOURCE_DIR}/include/GameObject.h"
    "${monke_platformer_SOURCE_DIR}/include/Hitbox.h"
    "${monke_platformer_SOURCE_DIR}/include/Vector.h"
    )

# Create an automatic library
add_library(game_core 
            GameManager.cpp 
            Camera.cpp 
            GameObject.cpp
            Hitbox.cpp
            Vector.cpp
            ${HEADER_LIST}
            )
# Include header files
target_include_directories(game_core PUBLIC ../include)
# Link required libraries
target_link_libraries(game_core PRIVATE SDL2)
# Use at least c++11
target_compile_features(game_core PUBLIC cxx_std_11)
