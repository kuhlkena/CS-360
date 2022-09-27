#include "Object.h"

class Sphere: public Object{
    public:

    Sphere();

    Sphere(Tuple Origin, double Radius, int Color[3]);

    Tuple origin;
    double r;
    
};