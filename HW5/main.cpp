#include "Scene.h"

int main() {
    // NOTE: In the current implementation there can be a maximum of 5 spheres and 5 planes in each workspace
    //colors:
    Rgb red(1,0,0);
    Rgb green(0,1,0);
    Rgb blue(0,0,1);
    Rgb yellow(1,1,0);
    Rgb bluegreen(0,1,1);

    //Scene for testing ray sphere intersect:
    Scene test2(200,4,4,4);
    test2.createSphere(Tuple(0,0,10,1), 2.5, yellow);
    test2.render("sphere_render.ppm"); // should output as a single black circle in the center of a white image
    
    //Scene for testing ray plane intersect:
    Scene test1(200,4,4,4);
    test1.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), yellow);
    test1.render("plane_render.ppm"); // should output a solid black image

    //Scene for testing item ordering:
    Scene test3(200,4,4,4);
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), red);
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,1,-1,0), green);
    test3.createSphere(Tuple(0,0,5,1), 1, blue);
    test3.render("complex_render.ppm"); // should output an image with red on top and green on bottom with a blue circle in the middle

    Tuple temp(1,.5,0,0);
    temp.normalize();
    cout<<temp<<endl;

    return 0;
}
