#include "Vehicle.h"

Vehicle::Vehicle() {
	std::cout << "Vehicle constructor called" << std::endl;
}

Vehicle::Vehicle(std::string _mark, std::string _model, int _year, std::string _version, std::string _engine, std::string _vin) : mark(_mark),model(_model), year(_year),version(_version),engine(_engine),vin(_vin){
	std::cout << "Vehicle argument constructor called" << std::endl;
}


std::string Vehicle::get_model() {
	return model;
}

std::string Vehicle::get_mark() {
	return mark;
}

int Vehicle::get_year() {
	return year;
}

std::string Vehicle::get_version() {
	return version;
}
std::string Vehicle::get_engine() {
	return engine;
}

std::string Vehicle::get_vin() {
	return vin;
}

void Vehicle::set_model(std::string& _model) {
	model = _model;
}

void Vehicle::set_mark(std::string& _mark) {
	mark = _mark;
}
void Vehicle::set_year(int & _year) {
	year = _year;
}

void Vehicle::set_version(std::string& _version) {
	version = _version;
}
void Vehicle::set_engine(std::string& _engine) {
	engine = _engine;
}

void Vehicle::set_vin(std::string& _vin) {
	vin = _vin;
}

void Vehicle::addService(Service *service)  {
	services.push_back(service);
}