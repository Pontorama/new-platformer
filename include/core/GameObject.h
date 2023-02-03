#ifndef GameObject_h
#define GameObject_h

#include "math/Vector.h"
#include "SDL2/SDL.h"
#include <string>

using Vector2 = Vector::Vector2;
using namespace std;
/*
 * Base class for all objects in a scene.
 */
class GameObject {
    public:
        GameObject();
        GameObject(string name);
        GameObject(string name, Vector2 pos);
        GameObject(GameObject& go);
        ~GameObject();

        virtual void update();
        virtual SDL_Texture* getTexture();

        Vector2 getPos();
        void setPos(Vector2 newPos);
        string getName();
    protected:
        Vector2 _pos;
        string _name;
};
#endif