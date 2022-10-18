#pragma once
#include "Tuple.h"
#include "Ray.h"

class Object{
    public:

    Object();

    int color[3];
    double reflect;
    double trance;
    double t;
    
    // 0 for plane 1 for sphere -1 for undefined
    int objType;

    virtual bool intersect(Ray& ray, double& distance);
};