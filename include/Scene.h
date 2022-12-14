#ifndef Scene_h
#define Scene_h

#include "GameObject.h"
#include "Camera.h"
#include "Player.h"
#include <stdio.h>
#include <vector>


class Scene {
    public:
        Scene(string filepath);
        ~Scene();
        vector<GameObject*> getLoadedGameObjects();
        Camera* getLoadedCamera(); // Currently only support one camera
        Player* getLoadedPlayer();
    private:
        vector<GameObject*> _loadedGameObjects;
        Camera* _loadedCamera;
        Player* _loadedPlayer;
};

#endif