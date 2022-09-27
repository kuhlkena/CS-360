#include "Object.h"

class Plane: public Object {
    public:

    Plane();

    Plane(Tuple Origin, Tuple Normal, int Color[3]);

    Tuple origin;
    Tuple normal;

};