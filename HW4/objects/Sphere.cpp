#include "Sphere.h"

Sphere::Sphere(){
    this->origin = Tuple(0,0,0,1);
    this->r = 1;
    this->color[0] = 0;
    this->color[1] = 0;
    this->color[2] = 0;
    this->objType = 1;
}

Sphere::Sphere(Tuple Origin, double Radius, int Color[3]){
    this->origin = Origin;
    this->r = Radius;
    this->color[0] = Color[0];
    this->color[1] = Color[1];
    this->color[2] = Color[2];
    this->objType = 1;
}

bool Object::intersect(Ray& ray, double& distance){
    // sphere ray intersect
}