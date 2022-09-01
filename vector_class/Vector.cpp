// Implementation

#include "Vector.h"

// default constructor
Time::Time() { 
	this->min = 0; 
}

// constructor
Time::Time(double m, double h) {
	double temp = h * 60;
	min = temp + this->min;
}

// add time object to time
void Time::add(const Time& OtherTimeObject) {
	this->min = this->min + OtherTimeObject.get_time();
}

// return the time in min
double Time::get_time() const{
	return this->min;
}