#include "Service.h"

int Service::counter=0;

Service::Service(/*Type type_,*/ int mileage_):/*type(type_),*/ mileage(mileage_) {
	++counter;
	id = counter;
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

time_t Service::getDate() {
	return date;
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

