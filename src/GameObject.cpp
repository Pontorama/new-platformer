#include "GameObject.h"

GameObject::GameObject(){
    _pos = Vector2();
}

GameObject::GameObject(string name, Vector2 pos){
    _name = name;
    _pos = pos;
}

GameObject::GameObject(GameObject& go){
    _name = go.getName();
    _pos = go.getPos();
}

GameObject::~GameObject(){

}

Vector2 GameObject::getPos(){
    return _pos;
}

string GameObject::getName(){
    return _name;
}

void GameObject::setPos(Vector2 newPos){
    _pos = newPos;
}
