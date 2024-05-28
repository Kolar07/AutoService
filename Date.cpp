#include "Date.h"

Date::Date() {}

Date::Date(int _day, int _month, int _year) :day{ _day }, month{ _month }, year{ _year } {}

Date& Date::operator=(const Date& other) {
	if (this == &other) {
		return *this;
	}
	else {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}
}

bool Date::operator==(const Date& rhs) {
	return day == rhs.day && month == rhs.month && year == rhs.year;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(int &_day) {
	day = _day;
}

void Date::setMonth(int& _month) {
	month = _month;
}

void Date::setYear(int& _year) {
	year = _year;
}

time_t Date::toTimeT() const {
	struct tm time = { 0 };
		time.tm_mday = day;
		time.tm_mon = month-1;
		time.tm_year = year - 1900;
		return mktime(&time);
}

Date Date::fromT(time_t _time) const {
	struct tm time;
	localtime_s(&time, &_time);
	return Date(time.tm_mday, time.tm_mon+1, time.tm_year+1900);
}

Date Date::addYears(int _years) const {
	time_t currentTime = toTimeT();
	struct tm time;
	localtime_s(&time,&currentTime);
	time.tm_year += _years;
	time_t newTime = mktime(&time);
	return fromT(newTime);
}

Date Date::addMonths(int _months) const {
	time_t currentTime = toTimeT();
	struct tm time; 
	localtime_s(&time,&currentTime);
	time.tm_mon += _months;
	if (time.tm_mon > 11) {
		time.tm_year += time.tm_mon/12;
		time.tm_mon %= 12;
	}
	else if (time.tm_mon < 0) {
		time.tm_year += (time.tm_mon / 12) - 1;
		time.tm_mon = 12 + (time.tm_mon % 12);
	}
	time_t newTime = mktime(&time);
	return Date::fromT(newTime);
}

Date Date::addDays(int days) const {
	time_t currentTime = toTimeT();
	time_t newTime = currentTime + days * 24 * 60 * 60;
	return Date::fromT(newTime);
}

void Date::display() const {
	std::cout << day << "/" << month << "/" << year << "." << std::endl;
}

int Date::daysBetween(const Date & other) {
	time_t thisTime = this->toTimeT();
	time_t otherTime = other.toTimeT();
	double difference = difftime(otherTime, thisTime);
	return static_cast<int>(difference/static_cast<double>(24*60*60));
}