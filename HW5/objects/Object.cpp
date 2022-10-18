#include "Object.h"

Object::Object(){
    color[0] = 255;
    color[1] = 255;
    color[2] = 255; 
}

bool Object::intersect(Ray& ray, double& distance){
    std::cout<<"default object intersect used"<<endl;
    return false;
}