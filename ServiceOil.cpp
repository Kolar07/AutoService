#include "ServiceOil.h"


std::string ServiceOil::getOil() {
	return oil;
}

std::string ServiceOil::getOilFilter() {
	return oilFilter;
}

std::string ServiceOil::getAirFilter() {
	return airFilter;
}

std::string ServiceOil::getCabinFilter() {
	return cabinFilter;
}

std::string ServiceOil::getType() {
	return type;
}

ServiceOil::ServiceOil(int mileage_, int _day, int _month, int _year, std::string _oil, std::string _oilFilter, std::string _airFilter, std::string _cabinFilter) :Service(mileage_, _day, _month, _year), oil(_oil), oilFilter(_oilFilter), airFilter(_airFilter), cabinFilter(_cabinFilter) {};

void ServiceOil::print() {
	std::cout << "Service id: " << Service::getID() << ", Type: "<<getType()  << ", mileage to the next service : " << Service::getMileage() << std::endl;

	std::cout << "Oil used: " << getOil() << ", oil filter used: " << getOilFilter() << ", air filter used: " << getAirFilter() << ", cabin filter used: " << getCabinFilter() << std::endl;

	std::cout << "Date: ";
	Service::getDate().display();
}