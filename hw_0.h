// Interface

class Time {
private:
	// variable to store time data in min
	double min;

public:
	// default constructor
	Time();

	// constructor
	Time(double m, double h);

	// add time object to time
	void add(const Time& OtherTimeObject);

	// return the time in min
	double get_time() const;
};