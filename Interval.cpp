#include "Interval.h"

Interval::Interval(int _days, int _months, int _years) :days(_days), months(_months), years(_years) {}
Interval::Interval() {}
bool Interval::operator==(const Interval &obj) {
	return (days == obj.days, months == obj.months, years == obj.years);
}

Interval& Interval::operator=(const Interval& obj) {
	if (this == &obj) {
		return *this;
	}
	else {
		this->days = obj.days;
		this->months = obj.months;
		this->years = obj.years;
		return *this;
	}
}

int Interval::getDays() const {
	return days;
}

int Interval::getMonths() const {
	return months;
}

int Interval::getYears() const {
	return years;
}

void Interval::setDays(int &_days) {
	days = _days;
}

void Interval::setMonths(int& _months) {
	months = _months;
}

void Interval::setYears(int& _years) {
	years = _years;
}