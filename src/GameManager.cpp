#include "GameManager.h"

GameManager::GameManager(){

}

GameManager::~GameManager(){
    // free game objects
    for(auto& go : _gameObjects){
        delete go;
    }
    _gameObjects.clear();
    // free camera
    delete _camera;
}
/**
 * @brief Update all game objects in scene
 * 
 */
void GameManager::update(){
    for(auto& go : _gameObjects){
        go->update();
    }
}

/**
 * @brief Render all gameobjects via camera
 * 
 */
void GameManager::render(){
    _camera->renderObjects(_renderables);
    // TODO: Render UI
}

/**
 * @brief Finds a game object by name.
 * Throws GameObjectNotFoundException if not found.
 * 
 * @param name 
 * @return GameObject* 
 */
GameObject* GameManager::getGameObject(string name){
    for(auto& go : _gameObjects){
        if(go->getName() == name){
            return go;
        }
    }
    throw GameObjectNotFoundException(name);
}

/**
 * @brief Update the main game loop. Handle inputs, 
 * update objects and render objects.
 * 
 */
void GameManager::gameLoopUpdate(){
    handleInput();
    update();
    render();
}

/**
 * @brief Add a game object to the manager.
 * 
 * @param go 
 */
void GameManager::addGameObject(GameObject* go){
    _gameObjects.push_back(go);
}

/**
 * @brief Remove a game object from scene by name.
 * Throws GameObjectNotFound if name not found.
 * 
 * @param name 
 */
void GameManager::removeGameObject(string name){
    for(int i = 0; i < _gameObjects.size(); i++){
        if(_gameObjects[i]->getName() == name){
            _gameObjects.erase(_gameObjects.begin() + i);
            return;
        }
    }
    throw GameObjectNotFoundException(name);
}