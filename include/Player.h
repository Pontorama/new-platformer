#ifndef Player_h
#define Player_h

#include "graphics/Animated.h"
#include "math/Vector.h"

using namespace Vector;

class Player : public Animated, public GameObject {
    public:
        Player();
        ~Player();
        Vector2 getPosition();
        void setPosition(Vector2 newPos);
    private:
        Vector2 _position;
        Vector2 _speed;
        
};

#endif