#include "Plane.h"

Plane::Plane(){
    this->origin = Tuple(0,0,0,1);
    this->normal = Tuple(0,0,1,1);
    this->color[0] = 0;
    this->color[1] = 0;
    this->color[2] = 0;
    this->objType = 0;

}

Plane::Plane(Tuple Origin, Tuple Normal, int Color[3]){
    Normal.normalize();
    this->origin = Origin;
    this->normal = Normal;
    this->color[0] = Color[0];
    this->color[1] = Color[1];
    this->color[2] = Color[2];
    this->objType = 0;
}

bool Object::intersect(Ray& ray, double& distance){
    // plane ray intersect
}
