#include "Workspace.h"

//Default constructor
Workspace::Workspace(){
    this->size = 100;
    this->w = 1;
    this->h = 1;
    this->front = 1;
    this->numPlanes = 0;
}

Workspace::Workspace(int imagePixelSize, double width, double height, double front_clip){
    this->size = imagePixelSize;
    this->w = width;
    this->h = height;
    this->front = front_clip;
    this->numPlanes = 0;
}


// create a sphere in our workplace and return true when done
bool Workspace::createSphere(Tuple position, double radius){
    this->spheres[this->numSpheres] = Sphere(position, radius);
    this->numSpheres++;
}

// create a plane in the workspace
bool Workspace::createPlane(Tuple position, Tuple vector){
    this->planes[this->numPlanes] = Plane(position, vector);
    this->numPlanes++;
}

//checks the colision of a ray with objects in the workspace and returns the distance to the hit along vector, returns -1 if there was no hit
double _rayHitPlane( const Ray& ray, const Plane& plane){
    //TODO
    return -1;
}

//Render the image and output with filename
void Workspace::render(std::string filename){

    PPM myImage = easyppm_create(this->size, this->size, IMAGETYPE_PPM);

    // Clear all image pixels to RGB color white.
    easyppm_clear(&myImage, easyppm_rgb(225, 255, 255));

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

            double angle = acos(R.direction.dot(Z)) * 180 / 3.14159;
            int level = round(angle * 1.4);

            //cout<<i<<"  "<<j<<endl;
            easyppm_set(&myImage, i, j, easyppm_rgb(level, level, level));
            
        }
    }
    // not using filename for now
    easyppm_write(&myImage, "gradient.ppm");
    easyppm_destroy(&myImage);
}

