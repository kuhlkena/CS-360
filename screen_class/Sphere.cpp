#include "Sphere.h"

Sphere::Sphere(){
    this->pos = Tuple(0,0,0,1);
    this->r = 1;
}

Sphere::Sphere(Tuple position, double radius){
    this->pos = position;
    this->r = radius;
}