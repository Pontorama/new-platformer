#ifndef SingleTexture_h
#define SingleTexture_h

#include "core/GameObject.h"
#include "graphics/Renderable.h"
#include "graphics/TextureUtils.h"
#include "SDL2/SDL.h"

class SingleTexture : public Renderable {
    public:
        SingleTexture();
        SingleTexture(string name, Vector2 pos);
        SingleTexture(string name, Vector2 pos, SDL_Texture* texture);
        ~SingleTexture();
    protected:
        SDL_Texture* _texture;
};

#endif