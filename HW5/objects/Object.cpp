#include "Object.h"

Object::Object(){
    this->t = 0;
}

bool Object::intersect(Ray& ray, double& distance){
    std::cout<<"default object intersect used"<<endl;
    return false;
}

Tuple getNormal(){
    return Tuple();
}