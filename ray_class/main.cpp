#include "Tuple.h"
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
	int myImageWidth = 320;
	int myImageHeight = 200;
	PPM myImage = easyppm_create(myImageWidth, myImageHeight, IMAGETYPE_PPM);

    // Clear all image pixels to RGB color white.
    easyppm_clear(&myImage, easyppm_rgb(255, 255, 255));

    int w = 1920;
    int h = 1080;
    int z = 500;

    Ray R;

    Tuple base(0 - (w/2),0 - (h/2), z, 1); // bottom left corner of screen

    for(int i = 0 - (w/2); i <= w/2; i++){
        for(int j = 0 - (h/2); j <= h/2; j++){
            //iterate over every point on the screen with a step of 1
            R.direction = Tuple(i,j,z,0); //vector from origin to point on screen
            Tuple P(i,j,z,0);
            double angle = acos(R.direction.dot(P));
            int level = 255 - round(angle);
            easyppm_set(&myImage, i, j, easyppm_rgb(level, level, level));
        }
    }
    return 0;
}
