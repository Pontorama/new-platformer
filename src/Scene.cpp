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
        
    }

}

void Scene::saveToJSON(Scene* sceneToSave){

}

// Class things

Scene::Scene(){
    // init vectors
    _loadedGameObjects = vector<GameObject*>();
}