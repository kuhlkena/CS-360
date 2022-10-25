#include "Scene.h"

void createFrame(int frameNum, double i){
    Scene image(1000,4,4,4);
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
    for(double i = 0; i < 500; i++){
        createFrame(i,i/50);
        cout<<i/50<<'%'<<endl;
    }

    return 0;
}
