#include "Workspace.h"

int main() {
    // NOTE: In the current implementation there can be a maximum of 5 spheres and 5 planes in each workspace
    //colors:
    int red[] = {200,0,0};
    int green[] = {0,200,0};
    int blue[] = {0,0,200};
    int yellow[] = {200,200,0};
    int bluegreen[] = {0,200,200};

    //Workspace for testing ray plane intersect:
    Workspace test1(200,4,4,4);
    test1.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), yellow);
    test1.render("plane_render.ppm"); // should output a solid black image

    //Workspace for testing ray sphere intersect:
    Workspace test2(200,4,4,4);
    test2.createSphere(Tuple(0,0,10,1), 2.5, yellow);
    test2.render("sphere_render.ppm"); // should output as a single black circle in the center of a white image

    //Workspace for testing item ordering:
    Workspace test3(1000,4,4,4);
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), red);
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,1,-1,0), green);
    test3.createSphere(Tuple(0,0,5,1), 1, blue);
    test3.render("complex_render.ppm"); // should output an image with red on top and green on bottom with a blue circle in the middle

    Tuple temp(1,.5,0,0);
    temp.normalize();
    cout<<temp<<endl;

    return 0;
}
