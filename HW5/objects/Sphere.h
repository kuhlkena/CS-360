#include "Object.h"

class Sphere: public Object{
    public:

    Sphere();

    Sphere(Tuple Origin, double Radius, Rgb Color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp);

    Tuple origin;
    double r;
    
    bool intersect(Ray& ray, double& distance);

    Tuple getNormal();
};