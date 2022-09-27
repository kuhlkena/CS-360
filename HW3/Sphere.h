#include "Tuple.h"

class Sphere{
    public:

    Sphere();

    Sphere(Tuple Origin, double Radius, int Color[3]);

    Tuple origin;
    double r;
    int color[3];
};