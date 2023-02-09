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

void Camera::renderObjects(vector<Renderable*> objectsToRender){
    // Clear screen first
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
    // Render game objects (renderables)
    for(auto& obj : objectsToRender){
        renderObject(obj);
    }
}

Vector2 Camera::translateScreenToWorld(Vector2 screenPos){
    Vector2 worldPos = screenPos*(1/_zoom);
    return worldPos + _pos;
}

Vector2 Camera::translateWorldToScreen(Vector2 worldPos){
    Vector2 screenPos = worldPos +  _pos*(-1);
    // Apply zoom
    return screenPos * _zoom;
}

SDL_Rect Camera::translateScreenToWorld(SDL_Rect screenRect){
    SDL_Rect worldRect;
    worldRect.x = (screenRect.x / _zoom) + _pos.getX();
    worldRect.y = (screenRect.y / _zoom) + _pos.getY();
    worldRect.w = screenRect.w / _zoom;
    worldRect.h = screenRect.h / _zoom;

    return worldRect;
}

SDL_Rect Camera::translateWorldToScreen(SDL_Rect worldRect){
    SDL_Rect screenRect;
    screenRect.x = (worldRect.x - _pos.getX()) * _zoom;
    screenRect.y = (worldRect.y - _pos.getY()) * _zoom;
    screenRect.w = worldRect.w * _zoom;
    screenRect.h = worldRect.h * _zoom;

    return screenRect;
}

void Camera::renderObject(Renderable* objToRender){
    // get texture and prepare rects
    SDL_Rect tmpSrcRect;
    SDL_Rect destRect;
    SDL_Texture* textureToRender = objToRender->getTexture();
    SDL_QueryTexture(textureToRender, NULL, NULL, &tmpSrcRect.x, &tmpSrcRect.y);

    destRect.x = objToRender->getPos().getX();
    destRect.y = objToRender->getPos().getY();
    destRect.w = tmpSrcRect.w;
    destRect.h = tmpSrcRect.h;
    
    //Transform to screen space
    tmpSrcRect = translateWorldToScreen(tmpSrcRect);
    destRect = translateWorldToScreen(destRect);

    // Finally add to render queue
    SDL_RenderCopy(_renderer, textureToRender, &tmpSrcRect, &destRect);
}

void Camera::renderUIObjects(vector<UIObject*> objectsToRender){

}

void Camera::setZoom(float newZoom){
    _zoom = newZoom;
}
