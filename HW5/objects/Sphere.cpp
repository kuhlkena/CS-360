#include "Sphere.h"

Sphere::Sphere(): Object {} {
    this->origin = Tuple(0,0,0,1);
    this->r = 1;
    this->color[0] = 0;
    this->color[1] = 0;
    this->color[2] = 0;
    this->objType = 1;
}

Sphere::Sphere(Tuple Origin, double Radius, int Color[3]): Object {} {
    this->origin = Origin;
    this->r = Radius;
    this->color[0] = Color[0];
    this->color[1] = Color[1];
    this->color[2] = Color[2];
    this->objType = 1;
}

bool Sphere::intersect(Ray& ray, double& distance){
    // sphere ray intersect
    double a = ray.direction.dot(ray.direction);
    Tuple V1 = Tuple(0,0,0) - this->origin;
    double b = 2 * V1.dot(ray.direction);
    double c = V1.dot(V1) - (this->r * this->r);

    double discriminant = b*b - 4*a*c; //note: discriminants is always 25 and abc always the same...
    
    //test print functions
    std::cout<<"Ray = "<<ray.direction<<std::endl;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2*a);
        double x2 = (-b - sqrt(discriminant)) / (2*a);
        distance = min(x1,x2);
        return true;
    }

    else if (discriminant == 0) {
        distance = -b/(2*a);
        return true;
    }
    else {
        distance = -1;
        return false;
    }
}