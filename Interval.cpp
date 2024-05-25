#include "Interval.h"

Interval::Interval(int _days, int _months, int _years) :days(_days), months(_months), years(_years) {}
Interval::Interval() {}
bool Interval::operator==(const Interval &obj) {
	return (this->days == obj.days, this->months == obj.months, this->years == obj.years);
}

Interval& Interval::operator=(const Interval& obj) {
	if (this == &obj) {
		return *this;
	}
	else {
		this->days = obj.days;
		this->months = obj.months;
		this->years = obj.years;
	}
}