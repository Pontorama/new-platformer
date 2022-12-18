#include "Animated.h"

Animated::Animated() {
	
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
