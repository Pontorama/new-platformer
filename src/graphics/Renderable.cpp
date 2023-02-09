#include "graphics/Renderable.h"

Renderable::Renderable() : GameObject() {
    
}

Renderable::Renderable(string name) : GameObject(name){

}

Renderable::Renderable(string name, Vector2 pos) : GameObject(name, pos){

}

Renderable::Renderable(Renderable& rend) : GameObject(rend){

}

Renderable::~Renderable(){
    
}