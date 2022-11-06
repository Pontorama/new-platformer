#ifndef Animated_h
#define Animated_h

#include "GameObject.h"
#include <vector>

using namespace std;

/**
 * @brief Animated object. 
 * 
 */
class Animated : GameObject {
    public:
        Animated();
        ~Animated();
    protected:
        vector<Sequence*> _sequences;
        Sequence* _currentSequence;
        SDL_Texture* _defaultTexture;
        SDL_Rect _defaultSrcRect;
        bool _useDefaultTexture;
};

/**
 * @brief Animation sequence, e.g. "Jump" or "Walk"
 * 
 */
class Sequence {
    public:
        Sequence(vector<Frame*> frames, string name);
        ~Sequence();

        SDL_Texture* getNextFrame();
        string getName();
        SDL_Rect getSrcRect();

    private:
        string _name;
        vector<Frame*> _frames;
        int _currentFrame;
        int _totalScreenFrameCount;
        int _screenFrameCounter;
};

/**
 * @brief Frame of animation sequence
 * 
 */
class Frame {
    public:
        Frame(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, int duration);
        ~Frame();

        SDL_Texture* getImage();
        SDL_Rect getSrcRect();
        int getDuration();
    private:
        SDL_Texture* _image;
        SDL_Rect _srcRect;
        int _duration;
};

#endif