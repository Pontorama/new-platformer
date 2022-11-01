#ifndef Vector_h
#define Vector_h

#include <math.h>

namespace Vector{
    class Vector2{
        public:
            // Constructors
            Vector2();
            Vector2(Vector2& v);
            Vector2(float x, float y);
            ~Vector2();
            // Operators
            Vector2& operator=(Vector2 v);
            float operator*(Vector2 v); // Dot multiplication
            Vector2& operator*=(float scalar); // Scale
            Vector2 operator*(float scalar); // Scalar mult
            Vector2 operator%(Vector2 v); // Elementwise multiplication
            Vector2 operator+(Vector2 v);
            Vector2 operator-(Vector2 v);
            // Functions
            float getX();
            float getY();
            void setX(float x);
            void setY(float y);
            void normalize();
            float getLength();
        private:
            float _x;
            float _y;
    };
};

#endif
