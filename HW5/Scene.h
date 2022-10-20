#include "objects/easyppm.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "objects/Ray.h"
#include "objects/Plane.h"
#include "objects/Sphere.h"
#include "objects/Lighting.h"

class Scene{

    public:
        //Default constructor
        Scene();

        Scene(int imagePixelSize, double width, double height, double front_clip);

        // create a sphere in our workplace and return true when done
        bool createSphere(Tuple position, double radius, Rgb color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp);

        // create a plane in the workspace
        bool createPlane(Tuple position, Tuple vector, Rgb color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp);

        //checks the colision of a ray with planes in the workspace
        bool _rayHitPlane( const Ray& ray, const Object& plane, double& T);

        //checks the colision of a ray with spheres in the workspace
        bool _rayHitSphere( const Ray& ray, const Object& sphere, double& T);

        //Render the image and output with filename
        void render(std::string filename);

    private:

        int size;
        double h;
        double w;
        double front;

        Object* objects[5];
        int numObjects;
};