#include "ServiceTiming.h"

ServiceTiming::ServiceTiming(int _mileage, int _day, int _month, int _year, std::string _timing) :Service(_mileage, _day,_month,_year),timing(_timing) {};

ServiceTiming::ServiceTiming() {}

ServiceTiming::ServiceTiming(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService, int _daysToNextService, int _monthsToNextService, int _yearsToNextService, std::string _timing) : Service(_mileage, _dayOfService, _monthOfService, _yearOfService, _daysToNextService, _monthsToNextService, _yearsToNextService), timing(_timing) {}

void ServiceTiming::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: " << getType() << ", date: " /*<< Service::getDate()*/ << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Timing used: " << getTiming() <<std::endl;
}

std::string ServiceTiming::getTiming() {
	return timing;
}

std::string ServiceTiming::getType() {
	return type;
}

std::unique_ptr<Service> ServiceTiming::clone() const {
	return std::make_unique<ServiceTiming>(*this);
}