#ifndef Camera_h
#define Camera_h

#include "GameObject.h"
#include "SDL2/SDL.h"
#include <vector>
#include "Renderable.h"
#include "UIObject.h"


using namespace std;
using namespace Vector;

class Camera : GameObject {
    public:
        Camera(SDL_Renderer* renderer);
        ~Camera();
        void renderGameObjects(vector<Renderable*> objectsToRender);
        void renderUIObjects(vector<UIObject*> objectsToRender);
        void setZoom(float newZoom);
        float getZoom();
        void setFollowMode(bool follow);
        void setObjectToFollow(GameObject* objToFollow);
    private:
        SDL_Renderer* _renderer;
        Vector2 translateScreenToWorld(Vector2 screenPos);
        Vector2 translateWorldToScreen(Vector2 worldPos);
        float _zoom;
        bool _followMode;
        GameObject* _objToFollow;
        Vector2 _viewSize;
        Vector2 _focusPoint;
        float _scrollSpeedX;
        float _scrollSpeedY;

        void renderObject(Renderable* objToRender);
};

#endif
