// Implementation

#include "Time.h"

Time::Time() // default constructor - set time value to 0 minutes
{
	this->minutes = 0;
}

Time::Time(double m) // initialize Time value to given number of minutes
{
	this->minutes = m;
}
    // Adds given Time value to this object. Use & for pass by reference to
    // avoid sending a copy of the argument's object.
void Time::add(const Time& otherTimeObject )
{
	this->minutes += otherTimeObject.getMin();
}

void Time::sub(const Time& otherTimeObject )
{
	this->minutes = this->minutes - otherTimeObject.getMin();
}

double Time::toMinutes() const // returns value in minutes
{
	return this->minutes;
}

double Time::toHours() const // returns value in hours
{
	return this->minutes / 60;
}

double Time::toDays() const // returns value in days
{
	return this->minutes / 1440;
}

void Time::printMinutes() const // prints X minutes. 
{
	std::cout<<this->minutes<<std::endl;
}
void Time::printHours() const // prints X hours. Tip - Call on toHours() for code reuse
{
	std::cout<<this->minutes / 60 <<std::endl;
}
void Time::printDays() const // prints X days. Tip - Call on toDays() for code reuse
{
	std::cout<<this->minutes / 1440 <<std::endl;
}

double Time::getMin() const
{
	return this->minutes;
}

// Main can say timeA + timeB
Time operator+(const Time& x, const Time& y){
	Time newTime = Time(x.minutes);
	newTime.add(y);
	return newTime;
}

Time operator-(const Time& x, const Time& y){
	double val = x.minutes - y.minutes;
	return Time(val);
}

//allow cout to print the min of a time object
std::ostream& operator<<(std::ostream& os, Time x){
	os << x.minutes << " min";
	return os; // send out the ostream
}

