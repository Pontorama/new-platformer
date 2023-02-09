#include "Platform.h"

Platform::Platform() : SingleTexture() {
}

Platform::Platform(string name, Vector2 pos) : SingleTexture(name, pos){

}

Platform::Platform(Platform& plat) : SingleTexture(plat) {
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