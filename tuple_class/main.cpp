#include "Tuple.h"

int main() {
    Tuple default_tup;
    Tuple A(10, 2, 3, 1); // create point (10, 2, 3), last value is w set to 1 for points
    Tuple B(-5, 2, 4, 1); // create point (-5, 2, 4)
    Tuple step(0,3,0);  // create vector (0,3,0); // its w value will be 0

    // should print: "default Tuple is ( 0, 0, 0, 0 )" to the console
    cout << "default Tuple is " << default_tup << endl;

    A.add(step); // Changes point A to be result of taking step (0,3,0).
                // We expect A to be the point (10, 5, 3)
    cout << "A is " << A << endl;

    Tuple C(A); // Create point C that is a copy of point A that is (10, 5, 3, 1)
    cout << "C is a copy of A " << C << endl; // Expect to see (10, 5, 3, 1)

    C.sub(B); // Compute vector that represents direction and magnitude of stepping
            // from point B to point C.
            // C = C - B
            // (10, 5, 3) - (-5, 2, 4) = (15, 3, -1)

    cout << "C is " << C << endl;
    // We expect to see a vector output of (15, 3, -1, 0)
    // Notice that the w value changed to 0 since subtracting two points
    // gives a displacement vector
    
    cout << "A is a vector? " << A.isVector() <<endl; // expect false

    cout << "A is a point? " << A.isPoint() <<endl; // expect true

    cout << "A has been multiplied by scalar 2: " << A * 2 << endl; // expect: ( 20, 10, 6, 1 )

    cout << "Magnitude of Step: " << step.magnitude() << endl; // expect 3.0

    step.normalize(); // normalize the magnitude of step
    cout << "normalized magnitude of Step: " << step.magnitude() << endl; // expect 1.0

    Tuple D(1,4,3,0); // create two new vectors
    Tuple E(5,1,2,0);

    cout << "Dot product of C and D: " << D.dot(E) << endl; // expect 15

    cout << "Printing A using print(): ";
    A.print(); // expect ( 10, 5, 3, 1 )

    cout << "Adding A and B: " << A + B << endl; // expect: ( 5, 7, 7, 1)

    cout << "Subracting C and D: " << D - E << endl; // expect: ( -4, 3, 1, 0)

}
