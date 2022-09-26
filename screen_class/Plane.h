#include "Tuple.h"

class Plane{
    public:

    Plane();

    Plane(Tuple Origin, Tuple Normal);

    Tuple origin;
    Tuple normal;
};