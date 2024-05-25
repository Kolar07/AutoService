#ifndef INTERVAL_H_
#define INTERVAL_H_

#include <iostream>

class Interval {
private:
	int days;
	int months;
	int years;
	
public:
	Interval();
	Interval(int _days, int _months, int _years);

	bool operator==(const Interval& obj);
	Interval& operator=(const Interval &obj);
};


#endif