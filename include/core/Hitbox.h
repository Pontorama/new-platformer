#ifndef Hitbox_h
#define Hitbox_h

#include "math/Vector.h"
#include "SDL2/SDL.h"

using namespace Vector;

int DEFAULT_MASK = 0;


class Hitbox{
    public:
        Hitbox();
        Hitbox(Vector2 pos, Vector2 size);
        Hitbox(Vector2 pos, Vector2 size, int mask);
        bool overlaps(Hitbox* other);
        void setPosition(Vector2 newPos);
        Vector2 getPos();
        Vector2 getPrevPos();
        void move(Vector2 v);
        Vector2 getSize();
        int getMask();
        void setMask(int newMask);
    private:
        Vector2 _pos;
        Vector2 _prevPos; // Previous position TODO needed or no?
        Vector2 _size;
        int _mask;
};

#endif 