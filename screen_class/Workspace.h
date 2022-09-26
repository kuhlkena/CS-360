#include "easyppm.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"

class Workspace{

    public:
        //Default constructor
        Workspace();

        Workspace(int imagePixelSize, double width, double height, double front_clip);

        // create a sphere in our workplace and return true when done
        bool createSphere(Tuple position, double radius, int color[3]);

        // create a plane in the workspace
        bool createPlane(Tuple position, Tuple vector, int color[3]);

        //checks the colision of a ray with planes in the workspace
        bool _rayHitPlane( const Ray& ray, const Plane& plane, double& T);

        //checks the colision of a ray with spheres in the workspace
        bool _rayHitSphere( const Ray& ray, const Sphere& sphere, double& T);

        //Render the image and output with filename
        void render(std::string filename);

    private:

        int size;
        double h;
        double w;
        double front;

        Sphere spheres[5];
        int numSpheres;

        Plane planes[5];
        int numPlanes;
};