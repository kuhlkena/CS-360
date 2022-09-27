#include "Tuple.h"

class Plane{
    public:

    Plane();

    Plane(Tuple Origin, Tuple Normal, int Color[3]);

    Tuple origin;
    Tuple normal;
    int color[3];
};