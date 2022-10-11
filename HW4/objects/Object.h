#pragma once
#include "Tuple.h"
#include "Ray.h"

class Object{
    public:

    int color[3];
    double reflect;
    double trance;
    double t;
    
    // 0 for plane 1 for sphere
    int objType;

    bool intersect(Ray& ray, double& distance);
};