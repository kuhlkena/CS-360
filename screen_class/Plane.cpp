#include "Plane.h"

Plane::Plane(){
    this->pos = Tuple(0,0,0,1);
    this->vector = Tuple(0,0,0,1);
}

Plane::Plane(Tuple position, Tuple vector){
    this->pos = position;
    this->vector = vector;
}