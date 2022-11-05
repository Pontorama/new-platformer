#ifndef Renderable_h
#define Renderable_h

#include "GameObject.h"
#include "SDL2/SDL.h"
/*
 * Base class for things to be rendered to screen
 * */
class Renderable : public GameObject {
    public:
        virtual SDL_Texture* getTexture();
};

#endif
