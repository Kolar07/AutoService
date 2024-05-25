#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <vector>
#include "Notification.h"
#include "Service.h"
#include <list>
#include "Interval.h"
#include <map>

class Vehicle {
private:
	std::string mark;
	std::string model;
	int year;
	std::string version;
	std::string engine;
	std::string vin;
	int intervalOil_km;
	int intervalTiming_km;
	Interval intervalOil;
	Interval intervalTiming;
	std::map<std::string, Interval> intervalOtherMap;
	std::vector<std::unique_ptr<Service>> services;
	std::vector<std::unique_ptr<Notification>> notifications;

public:
	Vehicle();
	Vehicle(std::string _mark, std::string _model, int _year, std::string _version, std::string _engine, std::string _vin);

	bool operator==(const Vehicle &obj) const;
	Vehicle &operator=( Vehicle& obj);

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
	void addService(std::unique_ptr<Service> service);
};

#endif