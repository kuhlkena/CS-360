#include "Ray.h"

Ray::Ray(){
    this->direction = Tuple(0,0,0,0);
    this->origin = Tuple(0,0,0,1);
}
