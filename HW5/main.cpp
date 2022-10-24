#include "Scene.h"

int main() {
    // NOTE: In the current implementation there can be a maximum of 5 spheres and 5 planes in each workspace

    Rgb lightAmbient(.3,.3,.3);
    Rgb lightDiffuse(.5,.5,.5);
    Rgb lightSpecular(.8,.8,.8);
    Tuple lightPoint(5,5,5,1);

    
    Scene image(10,4,4,4);
    image.createSphere(Tuple(1,0,10,1),1,Rgb(.5,0,0),Rgb(.8,0,0),Rgb(1,.5,.5),3); //red
    //image.createSphere(Tuple(-1,2,12,1),1,Rgb(.2,.2,.5),Rgb(.2,.2,.8),Rgb(.8,.8,1),3); //lightblue
    image.createSphere(Tuple(2,2,9,1), 1,Rgb(0,0,.5),Rgb(0,0,.8),Rgb(.5,.5,1),3); //blue
    //image.createSphere(Tuple(-2,-1.5,12,1),1,Rgb(0,.5,.5),Rgb(0,.8,.8),Rgb(.5,1,1),3); //bluegreen
    image.createSphere(Tuple(3,0,8.5,1),1,Rgb(.5,0,.5),Rgb(.8,0,.8),Rgb(1,.5,1),3); //pink
    image.createPlane(Tuple(-2,-2,20,1),Tuple(-1,-1,1,0),Rgb(.5,.5,.5),Rgb(.8,.8,.8),Rgb(1,1,1),3); //white

    image.createLight(new Light(.5,Tuple(5,5,5,1)));

    image.render("complex_render.ppm"); // should output as a single black circle in the center of a white image
    
    return 0;
}
