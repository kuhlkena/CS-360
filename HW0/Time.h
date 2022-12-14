#include <iostream>

class Time {
  private:
  // declare attribute data
  // Let's store the time value using the smallest time unit - minutes
  double minutes;
 
  public:
 
    Time(); // default constructor - set time value to 0 minutes

    Time(double m); // initialize Time value to given number of minutes
 
    // Adds given Time value to this object. Use & for pass by reference to
    // avoid sending a copy of the argument's object.
    void add(const Time& otherTimeObject );

    void sub(const Time& otherTimeObject );

    double toMinutes() const; // returns value in minutes

    double toHours() const; // returns value in hours

    double toDays() const; // returns value in days

    void printMinutes() const; // prints X minutes. 
    void printHours() const; // prints X hours. Tip - Call on toHours() for code reuse
    void printDays() const; // prints X days. Tip - Call on toDays() for code reuse

	  double getMin() const; // returns the private min variable

    // Main can say timeA + timeB
    friend Time operator+(const Time& x, const Time& y);

    friend Time operator-(const Time& x, const Time& y);

    //allow cout to print the min of a time object
    friend std::ostream& operator<<(std::ostream& os, Time x);
};