#include "graphics/SingleTexture.h"

SingleTexture::SingleTexture() : Renderable() {
    _texture = TextureUtils::getDefaultTexture();
}

SingleTexture::SingleTexture(string name, Vector2 pos) : Renderable(name, pos){
    _texture = TextureUtils::getDefaultTexture();   
}

SingleTexture::SingleTexture(string name, Vector2 pos, SDL_Texture* texture){
    _texture = texture;
}