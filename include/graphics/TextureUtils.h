#ifndef TextureUtils_h
#define TextureUtils_h

#include "SDL2/SDL.h"
#include <string>

// Constants
std::string DEFAULT_TEXTURE_PATH = ""; // TODO: set this

namespace TextureUtils {
    static SDL_Texture* getDefaultTexture();
    static SDL_Texture* loadTextureFromFile(SDL_Renderer* renderer, std::string fileName);
};

#endif