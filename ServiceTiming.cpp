#include "ServiceTiming.h"

ServiceTiming::ServiceTiming(int mileage_, std::string _timing) :Service(mileage_),timing(_timing) {};

void ServiceTiming::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: " << getType() << ", date: " << Service::getDate() << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Timing used: " << getTiming() <<std::endl;
}

std::string ServiceTiming::getTiming() {
	return timing;
}

std::string ServiceTiming::getType() {
	return type;
}