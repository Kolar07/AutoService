#ifndef DATE_H_
#define DATE_H_
#include <iostream>
#include <time.h>

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int _day, int _month, int _year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int& _day);
	void setMonth(int &_month);
	void setYear(int& _year);

	time_t toTimeT() const;
	Date fromT(time_t _time) const;
	Date addYears(int _years) const;
	Date addMonths(int _months) const;
	Date addDays(int _days) const;
	void display() const;
};



#endif