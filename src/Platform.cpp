#include "Platform.h"

Platform::Platform() : GameObject(), SingleTexture() {
}

Platform::Platform(string name, Vector2 pos) : GameObject(name, pos), SingleTexture(){

}

Platform::Platform(Platform& plat) : GameObject(plat), SingleTexture(plat) {
    for(auto& box : plat.getHitboxes()){
        _hitboxes.push_back(box);
    }
}

Platform::~Platform(){
    for(auto& box : _hitboxes){
        delete box;
    }
    _hitboxes.clear();
}

vector<Hitbox*> Platform::getHitboxes(){
    return _hitboxes;
}

void Platform::actOnCollision(Hitbox* other){
    // Do nothing for now
}