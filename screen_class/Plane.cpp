#include "Plane.h"

Plane::Plane(){
    this->origin = Tuple(0,0,0,1);
    this->normal = Tuple(0,0,0,1);
}

Plane::Plane(Tuple Origin, Tuple Normal){
    Normal.normalize();
    this->origin = Origin;
    this->normal = Normal;
}