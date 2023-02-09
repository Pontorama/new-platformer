#ifndef Platform_h
#define Platform_h

#include "core/GameObject.h"
#include "graphics/SingleTexture.h"
#include "core/Hitbox.h"
#include <vector>

using namespace Vector;
using namespace std;

class Platform : public SingleTexture {
    public:
        Platform();
        Platform(string name, Vector2 pos);
        Platform(string name, Vector2 pos, SDL_Texture* texture);
        Platform(Platform& plat);
        ~Platform();

        vector<Hitbox*> getHitboxes();
    private:
        vector<Hitbox*> _hitboxes;

        void actOnCollision(Hitbox* other);
};

#endif