#include "Sphere.h"

Sphere::Sphere(){
    this->origin = Tuple(0,0,0,1);
    this->r = 1;
}

Sphere::Sphere(Tuple Origin, double Radius){
    this->origin = Origin;
    this->r = Radius;
}