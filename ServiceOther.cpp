#include "ServiceOther.h"

ServiceOther::ServiceOther(int mileage_, std::string _other) :Service(mileage_), other(_other) {};

void ServiceOther::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: " << getType() << ", date: " << Service::getDate() << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Timing used: " << getOther() << std::endl;
}

std::string ServiceOther::getOther() {
	return other;
}

std::string ServiceOther::getType() {
	return type;
}