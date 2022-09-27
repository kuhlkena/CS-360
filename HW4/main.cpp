#include "Workspace.h"

int main() {
    // NOTE: In the current implementation there can be a maximum of 5 spheres and 5 planes in each workspace

    //Workspace for testing ray plane intersect:
    Workspace test1(200,4,4,4);
    int planeColor[] = {200,200,0};
    test1.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), planeColor);
    test1.render("plane_render.ppm"); // should output a solid black image


    //Workspace for testing ray sphere intersect:
    Workspace test2(200,4,4,4);
    int sphereColor[] = {200,200,0};
    test2.createSphere(Tuple(0,0,10,1), 2.5, sphereColor);
    test2.render("sphere_render.ppm"); // should output as a single black circle in the center of a white image

    //Workspace for testing item ordering:
    Workspace test3(1000,4,4,4);
    int planeColor2[] = {200,0,0};
    int planeColor3[] = {0,200,0};
    int sphereColor2[] = {0,0,200};
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,0,1,0), planeColor2);
    test3.createPlane(Tuple(0,0,10,1), Tuple(0,1,-1,0), planeColor3);
    test3.createSphere(Tuple(0,0,5,1), 1, sphereColor2);
    test3.render("complex_render.ppm"); // should output an image with red on top and green on bottom with a blue circle in the middle

    return 0;
}
