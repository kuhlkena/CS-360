#include "Time.h"
#include <iostream>

int main() {

	Time timeA = Time(1000.00);
	Time timeB = Time(30.00);

	timeA.add(timeB);

	timeA.printMinutes();
	timeB.printMinutes();

	timeA.printHours();
	timeB.printHours();

	timeA.printDays();
	timeB.printDays();
}