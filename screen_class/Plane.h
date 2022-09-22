#include "Tuple.h"

class Plane{
    public:

    Plane();

    Plane(Tuple position, Tuple vector);

    Tuple pos;
    Tuple vector;
};