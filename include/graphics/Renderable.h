#ifndef Renderable_h
#define Renderable_h

#include "core/GameObject.h"
#include "SDL2/SDL.h"

/**
 * @brief 
 * An interface for things to be rendered to the screen
 */
class Renderable : public GameObject {
    public:
        Renderable();
        Renderable(string name);
        Renderable(string name, Vector2 pos);
        Renderable(Renderable& rend);
        ~Renderable();
        virtual SDL_Texture* getTexture();
};

#endif