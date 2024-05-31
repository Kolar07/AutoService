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

	int getDays() const;
	int getMonths() const;
	int getYears() const;
	void setDays(int &_days);
	void setMonths(int &_months);
	void setYears(int &_years);
	void removeInterval(); //sets attributes to 0
};


#endif