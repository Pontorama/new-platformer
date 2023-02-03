#ifndef SingleTexture_h
#define SingleTexture_h

#include "core/GameObject.h"
#include "Renderable.h"
#include "SDL2/SDL.h"

class SingleTexture : Renderable {
    public:
        SingleTexture();
        SingleTexture(SDL_Texture* texture);
        SingleTexture(SDL_Texture* texture, SDL_Rect destRect, SDL_Rect srcRect);
        ~SingleTexture();
        SDL_Rect getDestRect();
        SDL_Rect getSrcRect();
    protected:
        SDL_Rect _destRect;
        SDL_Rect _srcRect;
        SDL_Texture* _texture;
};

#endif