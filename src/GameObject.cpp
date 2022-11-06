#include "GameObject.h"

GameObject::GameObject(){
    _pos = Vector2();
    _name = "unnamed";
    _visible = false;
}

GameObject::GameObject(string name){
    _pos = Vector2(0, 0);
    _name = name;
    _visible = false;
}

GameObject::GameObject(string name, Vector2 pos){
    _name = name;
    _pos = pos;
    _visible = false;
}

GameObject::GameObject(GameObject& go){
    _name = go._name;
    _pos = go._pos;
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

void GameObject::setVisible(bool visible){
    _visible = visible;
}

bool GameObject::isVisible(){
    return _visible;
}