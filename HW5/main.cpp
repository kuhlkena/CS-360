#include "Scene.h"

void createFrame(int frameNum, double i){
    Scene image(3000,4,4,4);
    image.createSphere(Tuple(1,5-(i*.8),10,1),1,Rgb(.5,0,0),Rgb(.8,0,0),Rgb(1,.5,.5),5); //red
    image.createSphere(Tuple(-1,7-(i*1.3),15,1),1,Rgb(0,0,.5),Rgb(0,0,.8),Rgb(.5,.5,1),5); //blue
    image.createSphere(Tuple(2,3-(i*.3),9,1), 1,Rgb(0,.5,0),Rgb(0,.8,0),Rgb(.5,1,.5),5); //green
    image.createSphere(Tuple(-2,3.5-(i*.9),12,1),1,Rgb(0,.5,.5),Rgb(0,.8,.8),Rgb(.5,1,1),5); //bluegreen
    image.createSphere(Tuple(3,5-(i*1.2),8.5,1),1,Rgb(.5,0,.5),Rgb(.8,0,.8),Rgb(1,.5,1),5); //pink

    image.createSphere(Tuple(4,-6+(i*.95),10,1),1,Rgb(0,.5,.5),Rgb(0,.8,.8),Rgb(.5,1,1),5); //bluegreen
    image.createSphere(Tuple(-2,-10+(i*1.4),13,1),1,Rgb(.5,0,.5),Rgb(.8,0,.8),Rgb(1,.5,1),5); //pink
    image.createSphere(Tuple(-3,0+(i*.5),12,1),1,Rgb(.5,0,0),Rgb(.8,0,0),Rgb(1,.5,.5),5); //red

    image.createPlane(Tuple(-1,-1.5,12,1),Tuple(-1,-1,1,0),Rgb(.5,.5,.5),Rgb(.8,.8,.8),Rgb(1,1,1),1); //white
    
    image.createLight(new Light(.5,Tuple(5,5,5,1)));
    image.createLight(new Light(.1,Tuple(5-(i),5-(i),5,1)));

    image.render(to_string(frameNum) + ".ppm"); // should output as a single black circle in the center of a white image
    }

int main() {
    /*
    for(double i = 0; i < 500; i++){
        createFrame(i,i/50);
        cout<<i/50<<'%'<<endl;
    }
    */

    Scene image(1000,4,4,4);
    image.createSphere(Tuple(-3,-2,10,1),2,Rgb(.3,.3,.3),Rgb(.5,.5,.5),Rgb(1,1,1),5); //white
    image.createSphere(Tuple(2,.5,11,1),2,Rgb(.3,.3,.3),Rgb(.5,.5,.5),Rgb(1,1,1),5); //white
    image.createSphere(Tuple(.5,4,9,1),2,Rgb(.3,.3,.3),Rgb(.5,.5,.5),Rgb(1,1,1),5); //white
    image.createSphere(Tuple(0,0,15,1),2,Rgb(.3,.3,.3),Rgb(.5,.5,.5),Rgb(1,1,1),5); //white

    image.createPlane(Tuple(0,0,20,1),Tuple(0,0,1),Rgb(.4),Rgb(.8),Rgb(1),3); //white

    //image.createLight(new Light(Rgb(0,0,.1),Rgb(.2,.2,.8),Rgb(.2,.2,1),Tuple(5,5,5,1)));//blue
    image.createLight(new Light(Rgb(.1,0,0),Rgb(.8,.2,.2),Rgb(1,.2,.2),Tuple(-5,-5,5,1)));//red

    image.render("test.ppm");
    return 0;
}
