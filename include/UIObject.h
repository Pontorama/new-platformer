#ifndef UIObject_h
#define UIObject_h

#include "SDL2/SDL.h"
#include "Vector.h"
#include <string>
/*
 * Base class for all UI objects
 * */

using namespace Vector;
using namespace std;

class UIObject {
    public:
        UIObject(string name);
        UIObject(string name, Vector2 screenPos);
        ~UIObject();
        virtual SDL_Texture* getTexture();
        Vector2 getScreenPos();
        void setScreenPos(Vector2 newPos);
        string getName();
    private:
        Vector2 _screenPos; // Position on screen
        string _name;
};

#endif
