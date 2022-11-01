#include "Vector.h"

using namespace Vector;
// CONSTRUCTORS
Vector2::Vector2(){
    _x = 0;
    _y = 0;
}

Vector2::Vector2(Vector2& v){
    _x = v.getX();
    _y = v.getY();
}

Vector2::Vector2(float x, float y){
    _x = x;
    _y = y;
}

Vector2::~Vector2(){

}
// OPERATOR DEFS
Vector2& Vector2::operator=(Vector2 v){
    _x = v.getX();
    _y = v.getY();
    return *this;
}

float Vector2::operator*(Vector2 v){
    return _x*v.getX() + _y*v.getY();
}

Vector2& Vector2::operator*=(float scalar){
    _x *= scalar;
    _y *= scalar;
    return *this;
}

Vector2 Vector2::operator*(float scalar){
    Vector2 out(_x*scalar, _y*scalar);
    return out;
}

Vector2 Vector2::operator%(Vector2 v){
    Vector2 out(_x*v.getX(), _y*v.getY());
    return out;
}

Vector2 Vector2::operator+(Vector2 v){
    Vector2 out(_x + v.getX(), _y + v.getY());
    return out;
}

Vector2 Vector2::operator-(Vector2 v){
    Vector2 out(_x - v.getX(), _y - v.getY());
    return out;
}
// FUNCTIONS
float Vector2::getX(){
    return _x;
}

float Vector2::getY(){
    return _y;
}

void Vector2::setX(float x){
    _x = x;
}

void Vector2::setY(float y){
    _y = y;
}

float Vector2::getLength(){
    return std::sqrt(_x*_x + _y*_y);
}

void Vector2::normalize(){
    float len = this->getLength();
    _x /= len;
    _y /= len;
}
