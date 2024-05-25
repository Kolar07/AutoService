#include "Service.h"

int Service::counter=0;

Service::Service(/*Type type_,*/ int _mileage, int _day, int _month, int _year):/*type(type_),*/ mileage(_mileage) {
	++counter;
	id = counter;
	dueDate = Date(_day, _month, _year);
}

Service::Service() {
	++counter;
	id = counter;
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

//std::string Service::getType() {
//	switch (type) {
//	case oil: {
//		return "oil + filters";
//	} break;
//	case finding: {
//		return "finding";
//	} break;
//	case other: {
//		return "other";
//	}break;
//	default: return "unknown";
//	}
//}

