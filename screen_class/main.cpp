#include "Workspace.h"

int main() {
    Tuple new1(1,0,1,1);
    cout<<new1.dot(new1)<<endl;

    //Workspace for testing ray plane intersect
    Workspace test1(200,4,4,4);
    //Create a plane
    Tuple planeNormal1(0,0,1,0);
    Tuple origin1(0,0,10,1);

    test1.createPlane(origin1, planeNormal1);
    test1.render("vertical_plane.ppm"); // should output a solid black image

    //Workspace for testing ray sphere intersect
    Workspace test2(200,4,4,4);
    test2.createSphere(origin1, 2.5);
    //create a sphere

}
