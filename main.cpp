#include "Vector.h"
#include <stdio.h>
#include <iostream>

int main(){
    Vector::Vector2 test(10, 15.5f);
    std::cout << test.getX() << " " << test.getY() << std::endl;
    return 0;
}
