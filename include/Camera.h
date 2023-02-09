#ifndef Camera_h
#define Camera_h

#include "core/GameObject.h"
#include "graphics/Renderable.h"
#include "SDL2/SDL.h"
#include <vector>
#include "ui/UIObject.h"
#include "graphics/Animated.h"


using namespace std;
using namespace Vector;

/*
    Class responsible for rendering things to screen.
    Cameras work with 2 coordinate systems; screen coordinates (pixels) and world coordinates.
*/

class Camera : public GameObject {
    public:
        Camera(SDL_Renderer* renderer);
        ~Camera();
        void renderObjects(vector<Renderable*> objectsToRender);
        void renderUIObjects(vector<UIObject*> objectsToRender);
        void setZoom(float newZoom);
        float getZoom();
        void setFollowMode(bool follow);
        void setObjectToFollow(GameObject* objToFollow);
    private:
        SDL_Renderer* _renderer;
        Vector2 translateScreenToWorld(Vector2 screenPos);
        Vector2 translateWorldToScreen(Vector2 worldPos);
        SDL_Rect translateWorldToScreen(SDL_Rect worldRect);
        SDL_Rect translateScreenToWorld(SDL_Rect screenRect);
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
