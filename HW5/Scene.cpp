#include "Scene.h"
Tuple camera(0,0,0,1);

//Default constructor
Scene::Scene(){
    this->size = 100;
    this->w = 1;
    this->h = 1;
    this->front = 1;
    this->numObjects = 0;
}

Scene::Scene(int imagePixelSize, double width, double height, double front_clip){
    this->size = imagePixelSize;
    this->w = width;
    this->h = height;
    this->front = front_clip;
    this->numObjects = 0;
}


// create a sphere in our workplace and return true when done
bool Scene::createSphere(Tuple origin, double radius, Rgb color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp){
    this->objects[this->numObjects] = new Sphere(origin, radius, color, ambient, diffuse, specular, specExp);
    this->numObjects++;
    return true;
}

// create a plane in the workspace
bool Scene::createPlane(Tuple origin, Tuple normal, Rgb color, Rgb ambient, Rgb diffuse, Rgb specular, int specExp){
    this->objects[this->numObjects] = new Plane(origin, normal, color, ambient, diffuse, specular, specExp);
    this->numObjects++;
    return true;
}

/* OLD INTERSECT METHODS
//checks the colision of a ray with objects in the workspace
bool Scene::_rayHitPlane( const Ray& ray, const Object& plane, double& T ){
    float den = plane.normal.dot(ray.direction);
    if (abs(den) > 0.001f){
        T = (plane.origin - ray.origin).dot(plane.normal) / den;
        if (T > 0) return true;
        
    }
    return false;
}

//checks the colision of a ray with spheres in the workspace
bool Scene::_rayHitSphere( const Ray& ray, const Object& sphere, double& T ){
    
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
*/
//Render the image and output with filename
void Scene::render(std::string filename){
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
            
            double closest = 1000; //This is the back clip
            int closestObj = -1;
            Rgb pixel;



            // for each object call intersect method
            
            for(int p = 0; p < numObjects; p++){
                if(objects[p]->intersect(R,distance)){
                    if(distance < closest){
                        closest = distance;
                        closestObj = p;
                    }
                }
            }
            
            //light calculations
            
            
            Rgb specular = lightSpecular(specularMaterial, objectPoint, objectNormal, specularIntensity, lightPoint, cameraPoint, specularExponent );


            if(closestObj > -1){ //if anything was hit get the closests objects color
                //TODO calculate point of intersect
                Tuple objectPoint = R.direction * closest;
                Tuple objectNormal =

                Rgb ambient = lightAmbient(objects[closestObj]->ambientMaterial, ambientIntensity );
                Rgb diffuse = lightDiffuse(objects[closestObj]->diffuseMaterial, objectPoint, objectNormal, diffuseIntensity, lightPoint );
            }

            easyppm_set(&myRender, i, this->size -1 - j, easyppm_rgb(pixel.getR(), pixel.getG(), pixel.getB()));
        
        }
    }
    easyppm_write(&myRender, ("out/"+filename).c_str());
    easyppm_destroy(&myRender);
}

