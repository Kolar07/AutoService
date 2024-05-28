#include "Service.h"

int Service::counter=0;

Service::Service(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService): mileage(_mileage) {
	++counter;
	id = counter;
	date = Date(_dayOfService, _monthOfService, _yearOfService);
}													//constructor with date of service

Service::Service(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService, int _daysToNextService, int _monthsToNextService, int _yearsToNextService) : mileage(_mileage) {
	++counter;
	id = counter;
	date = Date(_dayOfService, _monthOfService, _yearOfService);
	dueDate = Date(_daysToNextService, _monthsToNextService, _yearsToNextService);
}

Service::Service() {
	++counter;
	id = counter;
}

bool Service::operator==(const Service& obj) {
	return id == obj.id;
}

int Service::getCounter() {
	return counter;
}

Service::~Service() {

}

//void Service::print() {
//	std::cout << "Service id: " << getID() << " Type: " << getType() << ", date: " << getDate() << ", mileage to the next service: " << getMileage() << std::endl;;
//}

int Service::getID() {
	return id;
}

int Service::getMileage() {
	return mileage;
}

Date Service::getDate() {
	return date;
}

Date Service::getDueDate() {
	return dueDate;
}

void Service::setDueDate(int _days, int _months, int _years) {
	date = Date(_days, _months, _years);
}

void Service::setDueDate(Date _date) {
	dueDate = _date;
}

void Service::setDueDateByInterval(Interval _interval) {
	Date dueDate(_interval.getDays(), _interval.getMonths(), _interval.getYears());
	setDueDate(dueDate);
}
