#include "Object.h"

class Plane: public Object {
    public:

    Plane();

    Plane(Tuple Origin, Tuple Normal, Rgb Color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp);

    Tuple origin;
    Tuple normal;

    bool intersect(Ray& ray, double& distance);

    Tuple getNormal();

};