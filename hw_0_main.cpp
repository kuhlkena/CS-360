#include "hw_0.h"
#include <iostream>

int main() {

	Time timeA = Time(1.00, 4.00);
	Time timeB = Time(30.00, 0.00);

	timeA.add(timeB);

	std::cout << timeA.get_time();
}