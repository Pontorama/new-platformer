#ifndef Renderable_h
#define Renderable_h

#include "SDL2/SDL.h"

/**
 * @brief 
 * An interface for things to be rendered to the screen
 */
class Renderable {
    public:
        SDL_Texture* getTexture();
};

// Static function that I didnt know where to put
static SDL_Texture* getDefaultTexture();

#endif