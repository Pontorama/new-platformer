#ifndef Scene_h
#define Scene_h

#include "core/GameObject.h"
#include "Camera.h"
#include "Player.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;
using json = nlohmann::json;

// Supported types listed here
string PLAYER_T = "Player";
string CAMERA_T = "Camera";
string PLATFORM_T = "Platform";

class Scene {
    public:
        Scene();
        Scene(string filepath, SDL_Renderer* renderer);
        ~Scene();
        vector<GameObject*> getLoadedGameObjects();
        Camera* getLoadedCamera(); // Currently only support one camera
        Player* getLoadedPlayer();
        static Scene* loadFromJSON(string filepath, SDL_Renderer* renderer);
        static void saveToJSON(Scene* sceneToSave);
    private:
        vector<GameObject*> _loadedGameObjects;
        Camera* _loadedCamera;
        Player* _loadedPlayer;
};

#endif