#include "Object.h"

Object::Object(){
    this->t = 0;
}

bool Object::intersect(const Ray& ray, double& distance){
    std::cout<<"default object intersect used"<<endl;
    return false;
}

Tuple Object::getNormal(){
    return Tuple();
}