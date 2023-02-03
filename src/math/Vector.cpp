#include "math/Vector.h"

using namespace Vector;
// CONSTRUCTORS
Vector2::Vector2(){
    _x = 0;
    _y = 0;
}

Vector2::Vector2(const Vector2& v){
    _x = v._x;
    _y = v._y;
}

Vector2::Vector2(float x, float y){
    _x = x;
    _y = y;
}

Vector2::~Vector2(){

}
// OPERATOR DEFS
Vector2& Vector2::operator=(Vector2 v){
    _x = v._x;
    _y = v._y;
    return *this;
}

float Vector2::operator*(const Vector2& v) const{
    return _x*v._x + _y*v._y;
}

Vector2 Vector2::operator*=(float scalar){
    _x *= scalar;
    _y *= scalar;
    return *this;
}

Vector2 Vector2::operator*(float scalar){
    return Vector2(_x*scalar, _y*scalar);
}

Vector2 Vector2::operator%(const Vector2& v) const {
    Vector2 out(_x*v._x, _y*v._y);
    return out;
}

Vector2 Vector2::operator+(const Vector2& v) const{
    return Vector2(_x + v._x, _y + v._y);
}

Vector2 Vector2::operator-(const Vector2& v) const{
    Vector2 out(_x - v._x, _y - v._y);
    return out;
}

Vector2& Vector2::operator+=(Vector2 v){
    _x += v._x;
    _y += v._y;
    return *this;
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
    return sqrt(_x*_x + _y*_y);
}

void Vector2::normalize(){
    float len = this->getLength();
    _x /= len;
    _y /= len;
}
