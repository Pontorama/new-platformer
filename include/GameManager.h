#ifndef GameManager_h
#define GameManager_h

#include <vector>
#include "GameObject.h"
#include <cstdio>

using namespace std;
/*
    Class to handle scenes in game.
    Responsible for updating, hitbox proximity updates,
*/
class GameManager{
    public:
        GameManager();
        ~GameManager();
        void update();
        GameObject* getGameObject(string name);
        void addGameObject(GameObject* go);
        void removeGameObject(string name);
    private:
        vector<GameObject*> _gameObjects; // All game objects handled
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
