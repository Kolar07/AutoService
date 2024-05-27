#include "ServiceOther.h"

ServiceOther::ServiceOther(int _mileage, int _day, int _month, int _year, std::string _service) :Service(_mileage,_day,_month,_year), service(_service) {};

ServiceOther::ServiceOther() {}

void ServiceOther::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: " << getType() << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Parts used: " << getOther() << std::endl;
	std::cout << "Date: "; Service::getDate().display();
}

std::string ServiceOther::getOther() {
	return service;
}

std::string ServiceOther::getType() {
	return type;
}

std::unique_ptr<Service> ServiceOther::clone() const {
	return std::make_unique<ServiceOther>(*this);
}