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
    easyppm_clear(&myImage, easyppm_rgb(255, 255, 255));

    double w = 4;
    double h = 4;
    int front_clip = 4;

    Ray R;
    Tuple B(-(w/2),0 -(h/2), front_clip, 1); // bottom left corner of screen
    Tuple X(1,0,0,0);
    Tuple Y(0,1,0,0);
    Tuple Z(0,0,1,0);

    for(double i = 0; i <= w; i = i + (w/imagePixelSize)){
        for(double j = 0; j <= h; j = j + (h/imagePixelSize)){
            Tuple P = B + i*X + j*Y;
            R.direction = P - R.origin;
            R.direction.normalize();

            double angle = acos(R.direction.dot(Z)) * 180 / 3.14159;
            int level = round(angle);

            easyppm_set(&myImage, i * (imagePixelSize/w), j * (imagePixelSize/h), easyppm_rgb(level, level, level));

        }
    }
    easyppm_write(&myImage, "gradient.ppm");
    easyppm_destroy(&myImage);
    return 0;
}
