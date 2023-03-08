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

Animated* loadAnimatedFromJSON(json::object_t animatedObject, SDL_Renderer* renderer){
    // Load file
    string animatedDescFilePath = animatedObject["animations"];
    ifstream animatedJsonDescFile(animatedDescFilePath);
    json::object_t animationDefJson = json::parse(animatedJsonDescFile);
    // Get metadata
    string imagePath = animationDefJson["meta"]["image"].get<string>();
    SDL_Texture* fullImage = TextureUtils::loadTextureFromFile(renderer, imagePath);
    json::object_t sequenceDescs = animationDefJson["meta"]["frameTags"];

    for(){
        vector<Frame*> seqFrames;
        string seqName = (*seq)["name"].get<string>();
    }

    json::object_t frames = animatedObject["frames"];

    // Free sprite sheet image
    SDL_DestroyTexture(fullImage);
}

Frame* loadFrame(json::object_t frameDesc, SDL_Texture* spriteSheet, SDL_Renderer* renderer){
    // Get frame metadata
    // Fields to read from each frame:
    // - "frame" contains what pixels from the image the frame contains
    // - "duration" contains how long the frame should  be displayed, in ms

    // Get sub-image size
    SDL_Rect srcRect;
    srcRect.x = frameDesc["frame"]["x"].get<int>();
    srcRect.y = frameDesc["frame"]["y"].get<int>();
    srcRect.w = frameDesc["frame"]["w"].get<int>();
    srcRect.h = frameDesc["frame"]["h"].get<int>();
    SDL_Rect destRect = {0,0,srcRect.w, srcRect.h};
    // Copy the correct part of the full image
    // Potential FIXME, pixelformat and texture access
    SDL_Texture* image = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, srcRect.w, srcRect.h);
    // FIXME how to handle transparency?
    SDL_SetRenderTarget(renderer, image);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_SetTextureBlendMode(image, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, &destRect);
    // Reset target back to screen
    SDL_SetRenderTarget(renderer, NULL);
    // Get frame duration and convert it to screen frames 
    int duration = (int)(frameDesc["duration"].get<int>() / (TIME_PER_FRAME * 1.f));

    return new Frame(image, duration);
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