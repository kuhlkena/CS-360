#include "easyppm.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "Ray.h"

void _test(bool pass){
        if(pass){
            cout<<"Passed"<<endl;
        }
        else{
            cout<<"Test Failed"<<endl;
        }
    }

int main() {
    // Create image of desired dimensions.
	int imagePixelSize = 200;
	PPM myImage = easyppm_create(imagePixelSize, imagePixelSize, IMAGETYPE_PPM);

    // Clear all image pixels to RGB color white.
    easyppm_clear(&myImage, easyppm_rgb(0, 255, 255));

    double w = 4;
    double h = 4;
    double front_clip = 4;

    Ray R;
    Tuple B(-(w/2),0 -(h/2), front_clip, 1); // bottom left corner of screen
    Tuple Camera(0,0,0,1);
    Tuple X(1,0,0,0);
    Tuple Y(0,1,0,0);
    Tuple Z(0,0,1,0);

    // I opted to use incraments of 1 rather than w/imagePixelSize in my loop because using a float was causing some strange issues
    for(int i = 0; i < imagePixelSize; i++){
        for(int j = 0; j < imagePixelSize; j++){

            float stepX = i/(imagePixelSize/w);
            float stepY = j/(imagePixelSize/h);

            Tuple P = B + stepX*X + stepY*Y;
            R.set(Camera, P);

            double angle = acos(R.direction.dot(Z)) * 180 / 3.14159;
            int level = round(angle * 1.4);

            //cout<<i<<"  "<<j<<endl;
            easyppm_set(&myImage, i, j, easyppm_rgb(level, level, level));
            
        }
    }
    easyppm_write(&myImage, "gradient.ppm");
    easyppm_destroy(&myImage);
    return 0;
}
