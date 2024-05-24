#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <vector>
#include "Notification.h"
#include "Service.h"

class Vehicle {
private:
	std::string mark;
	std::string model;
	int year;
	std::string version;
	std::string engine;
	std::string vin;
	int intervalOil_km = 15000;
	int intervalOil_time;
	int intervalTiming_km = 15000;
	int intervalTiming_time;
	std::vector<Service*> services;
	std::vector<Notification> notifications;

public:
	Vehicle();
	Vehicle(std::string _mark, std::string _model, int _year, std::string _version, std::string _engine, std::string _vin);

	std::string get_mark();
	std::string get_model();
	int get_year();
	std::string get_version();
	std::string get_engine();
	std::string get_vin();
	void set_mark(std::string& _mark);
	void set_model(std::string& _model);
	void set_year(int & _year);
	void set_version(std::string& _version);
	void set_engine(std::string& _engine);
	void set_vin(std::string& _vin);
	void addService(Service* service);
};

#endif