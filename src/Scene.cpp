#include "Scene.h"

// Helper functions

SDL_Texture* loadImageFromSpriteSheet(SDL_Texture* spriteSheet, SDL_Renderer* renderer, SDL_Rect srcRect){
    SDL_Texture* target;
    // Clear texture
    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    // Copy correct part of spritesheet
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, NULL);
    // Reset renderer to the screen
    SDL_SetRenderTarget(renderer, NULL);

    return target;
}


// Statics

Scene* Scene::loadFromJSON(string filepath, SDL_Renderer* renderer){
    ifstream inputFile(filepath);
    json loadedFields = json::parse(inputFile);
    Scene* scene = new Scene();

    for(auto& el : loadedFields){
        string type = el["type"].get<string>();
        if(type == PLAYER_T){
            loadPlayerFromJSON(el);
        }else if (type == CAMERA_T)
        {
            loadCameraFromJSON(el);
        }else if(type == PLATFORM_T){
            
        }
        
    }

}

void Scene::saveToJSON(Scene* sceneToSave){

}

// Loader functions
Player* loadPlayerFromJSON(json::object_t playerObject){
    Player* p = new Player();
    Vector::Vector2 position = {playerObject["position"]["x"].get<float>(), 
                                playerObject["position"]["y"].get<float>()};
    p->setPosition(position);

    return p;
}

Camera* loadCameraFromJSON(json::object_t cameraObject){

}

//Platform* loadPlatformFromJSON(json::object_t platformObject){
//}

vector<GameObject*> loadGameObjectFromJSON(json::object_t object){
    string gameType = object["type"];
    vector<GameObject*> loaded;
    if(gameType == PLAYER_T){
        Player* p = loadPlayerFromJSON(object);
        loaded.push_back(p);
    }else if(gameType == CAMERA_T){
        Camera* c = loadCameraFromJSON(object);
        loaded.push_back(c);
    }else if(gameType == PLATFORM_T){

    }
}
// Class things

Scene::Scene(){
    // init vectors
    _loadedGameObjects = vector<GameObject*>();
}