#include "graphics/Animated.h"

Animated::Animated() : Renderable() {
	_defaultTexture = TextureUtils::getDefaultTexture();
}

Animated::~Animated() {
	
}
// --------
// SEQUENCE
Sequence::Sequence(vector<Frame*> frames, string name) {
	_frames = frames;
    _name = name;
}

Sequence::~Sequence() {
	// Clear frames
    for(auto& frame : _frames){
        delete frame;
    }
    _frames.clear();
}

SDL_Texture* Sequence::getNextFrame() {
    int durationSum = 0;
    for(int i = 0; i < _frames.size(); i++){
        // Floor division to select correct frame to display
        if(durationSum / (_screenFrameCounter + 1) > 0){
            _screenFrameCounter++;
            return _frames[i]->getImage();
        }
        durationSum += _frames[i]->getDuration();
    }
    _screenFrameCounter = 0;
    return _frames[_currentFrame]->getImage();
}

string Sequence::getName() {
	return _name;
}

SDL_Rect Sequence::getSrcRect() {
	return _frames[_currentFrame]->getSrcRect();
}
// -----
// FRAME
Frame::Frame(SDL_Texture* texture, SDL_Rect srcRect, int duration) {
    _image = texture;
    _duration = duration;
}

Frame::~Frame() {
	SDL_DestroyTexture(_image);
}

SDL_Texture* Frame::getImage() {
    return _image;
}

int Frame::getDuration() {
	return _duration;
}
