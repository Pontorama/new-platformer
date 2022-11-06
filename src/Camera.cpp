#include "Camera.h"

Camera::Camera(SDL_Renderer* renderer){
    _renderer = renderer;
    _pos = {0, 0};
    _objToFollow = nullptr;
    _zoom = 1;
    _scrollSpeedX = 1;
    _scrollSpeedY = 1;
    _followMode = false;
}

Camera::~Camera(){
    SDL_DestroyRenderer(_renderer);
}

void Camera::renderGameObjects(vector<GameObject*> objectsToRender){
    // Clear screen first
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
    // Render game objects (renderables)
    for(auto& obj : objectsToRender){
        renderObject(obj);
    }
}

void Camera::renderObject(GameObject* objToRender){

}

void Camera::renderUIObjects(vector<UIObject*> objectsToRender){

}

void Camera::setZoom(float newZoom){

}
