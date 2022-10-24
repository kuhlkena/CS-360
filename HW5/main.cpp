#include "Scene.h"

int main() {
    // NOTE: In the current implementation there can be a maximum of 5 spheres and 5 planes in each workspace
    //colors:
    Rgb ambient(0.5,0,0);
    Rgb diffuse(0.8,0,0);
    Rgb specular(0.8,0,0);
    Rgb lightAmbient(.3,.3,.3);
    Rgb lightDiffuse(.5,.5,.5);
    Rgb lightSpecular(.5,.5,.5);
    Tuple lightPoint(5,5,5,1);

    //Scene for testing ray sphere intersect:
    Scene test2(10,4,4,4);
    test2.createSphere(Tuple(0,0,10,1), 2.5,ambient,diffuse,specular,4);
    test2.createLight(lightAmbient,lightDiffuse,lightSpecular,lightPoint);
    test2.render("sphere_render.ppm"); // should output as a single black circle in the center of a white image

    return 0;
}
