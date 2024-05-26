#include "ServiceOther.h"

//ServiceOther::ServiceOther(int mileage_, std::string _other) :Service(mileage_), other(_other) {};

void ServiceOther::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: " << getType() << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Parts used: " << getOther() << std::endl;
	std::cout << "Date: "; Service::getDate().display();
}

std::string ServiceOther::getOther() {
	return other;
}

std::string ServiceOther::getType() {
	return type;
}

std::unique_ptr<Service> ServiceOther::clone() const {
	return std::make_unique<ServiceOther>(*this);
}