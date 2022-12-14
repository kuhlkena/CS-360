#include "Workspace.h"
Tuple camera(0,0,0,1);

//Default constructor
Workspace::Workspace(){
    this->size = 100;
    this->w = 1;
    this->h = 1;
    this->front = 1;
    this->numPlanes = 0;
    this->numSpheres = 0;
}

Workspace::Workspace(int imagePixelSize, double width, double height, double front_clip){
    this->size = imagePixelSize;
    this->w = width;
    this->h = height;
    this->front = front_clip;
    this->numPlanes = 0;
    this->numSpheres = 0;
}


// create a sphere in our workplace and return true when done
bool Workspace::createSphere(Tuple origin, double radius, int color[3]){
    this->spheres[this->numSpheres] = Sphere(origin, radius, color);
    this->numSpheres++;
    return true;
}

// create a plane in the workspace
bool Workspace::createPlane(Tuple origin, Tuple normal, int color[3]){
    this->planes[this->numPlanes] = Plane(origin, normal, color);
    this->numPlanes++;
    return true;
}

//checks the colision of a ray with objects in the workspace
bool Workspace::_rayHitPlane( const Ray& ray, const Plane& plane, double& T ){
    float den = plane.normal.dot(ray.direction);
    if (abs(den) > 0.001f){
        T = (plane.origin - ray.origin).dot(plane.normal) / den;
        if (T > 0) return true;
        
    }
    return false;
}

//checks the colision of a ray with spheres in the workspace
bool Workspace::_rayHitSphere( const Ray& ray, const Sphere& sphere, double& T ){
    
    double a = ray.direction.dot(ray.direction);
    Tuple V1 = camera - sphere.origin;
    double b = 2 * V1.dot(ray.direction);
    double c = V1.dot(V1) - (sphere.r * sphere.r);

    double discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2*a);
        double x2 = (-b - sqrt(discriminant)) / (2*a);
        T = min(x1,x2);
        return true;
    }

    else if (discriminant == 0) {
        T = -b/(2*a);
        return true;
    }
    else {
        T = -1;
        return false;
    }
}

//Render the image and output with filename
void Workspace::render(std::string filename){

    PPM myRender = easyppm_create(this->size, this->size, IMAGETYPE_PPM);

    // Clear all image pixels to RGB color white.
    easyppm_clear(&myRender, easyppm_rgb(225, 255, 255));

    Ray R;
    Tuple B(-(this->w/2),0 -(this->h/2), this->front, 1); // bottom left corner of screen
    Tuple Camera(0,0,0,1);
    Tuple X(1,0,0,0);
    Tuple Y(0,1,0,0);
    Tuple Z(0,0,1,0);

    // I opted to use incraments of 1 rather than w/imagePixelSize in my loop because using a float was causing some strange issues
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){

            float stepX = i/(this->size/this->w);
            float stepY = j/(this->size/this->h);

            Tuple P = B + stepX*X + stepY*Y;
            R.set(Camera, P);

            double distance = 0;
            int level[3] = {255,255,255};
            
            double closest = 1000; //This is the back clip
            int closestObj = -1;

            for(int p = 0; p < numPlanes; p++){
                if(_rayHitPlane(R, planes[p], distance)) {
                    if(distance < closest){
                        closest = distance;
                        closestObj = p;
                    }
                }
            }

            for(int s = 0; s < numSpheres; s++){
                if(_rayHitSphere(R, spheres[s], distance)) {
                    if(distance < closest){
                        closest = distance;
                        closestObj = s + 5;
                    }
                }
            }
            
            if(closestObj > 4){ // closest object is a sphere
                int temp = closestObj - 5;
                level[0] = spheres[temp].color[0];
                level[1] = spheres[temp].color[1];
                level[2] = spheres[temp].color[2];
            }

            if(closestObj >= 0 && closestObj < 5){ // closest object is a plane
                level[0] = planes[closestObj].color[0];
                level[1] = planes[closestObj].color[1];
                level[2] = planes[closestObj].color[2];
            }
            
            easyppm_set(&myRender, i, 199 - j, easyppm_rgb(level[0], level[1], level[2]));
        
        }
    }
    easyppm_write(&myRender, filename.c_str());
    easyppm_destroy(&myRender);
}

