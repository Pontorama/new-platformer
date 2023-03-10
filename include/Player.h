#ifndef Player_h
#define Player_h

#include "graphics/Animated.h"
#include "math/Vector.h"

using namespace Vector;

class Player : public Animated {
    public:
        Player();
        Player(Vector2 pos);
        ~Player();
        Vector2 getPosition();
        void update();
        void setPosition(Vector2 newPos);

        void handleEvents(SDL_Event e);
    private:
        Vector2 _position;
        Vector2 _speed;
        
        Vector2 PLAYER_MAX_SPEED;
        float PLAYER_MAX_DIR_LEN = 1.5f;
        float PLAYER_SLOWDOWN_ACC = 0.1f;
};

#endif
