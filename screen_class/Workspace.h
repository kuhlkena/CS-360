#include "easyppm.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "Ray.h"
#include "Plane.h"

class Workspace{

    public:
        //Default constructor
        Workspace();

        Workspace(int imagePixelSize, double width, double height, double front_clip);

        // create a sphere in our workplace and return true when done
        bool createSphere(Tuple position, double radius);

        // create a plane in the workspace
        bool createPlane(Tuple position, Tuple vector);

        //Render the image and output with filename
        void render(std::string filename);


    private:

        //checks the colision of a ray with objects in the workspace and returns the distance to the hit along vector, returns -1 if there was no hit
        double _rayHitPlane( const Ray& ray, const Plane& plane);

        int size;
        double h;
        double w;
        double front;

        Tuple sPos;
        double sRadius;

        Plane planes[5];
        int numPlanes;
};