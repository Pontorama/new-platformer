#ifndef GameManager_h
#define GameManager_h

#include <vector>
#include "GameObject.h"
#include "Camera.h"
#include "Player.h"
#include <cstdio>

using namespace std;
/*
    Class to manage the game and the objects in it.
    Responsible for updating, hitbox proximity updates,
*/
class GameManager{
    public:
        GameManager();
        ~GameManager();
        GameObject* getGameObject(string name);
        void addGameObject(GameObject* go);
        void removeGameObject(string name);
    private:
        vector<GameObject*> _gameObjects; // All game objects handled
        Player* _player;
        Camera* _camera;
        void gameLoopUpdate();
        void update();
        void handleInput();
        void render();
};

// Exceptions related to this class
class GameObjectNotFoundException : exception {
    private:
        string _gameObjectName;
    public:
        GameObjectNotFoundException(string gameObjectName) : 
            _gameObjectName(gameObjectName){}
        char* what(){
            char buffer[100];
            sprintf(buffer, "Game object: '%s' not found.", _gameObjectName);
            return buffer;
        }
};

#endif
