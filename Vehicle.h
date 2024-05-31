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
	std::map<int, Interval> intervalOtherMap;
	std::vector<std::unique_ptr<Service>> services;
	std::vector<std::unique_ptr<Notification>> notifications;

public:
	Vehicle();
	Vehicle(std::string _mark, std::string _model, int _year, std::string _version, std::string _engine, std::string _vin);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(Vehicle&& other) noexcept;
	~Vehicle() = default;

	bool operator==(const Vehicle &obj) const;
	Vehicle &operator=(const Vehicle& obj);

	std::string getMark() const;
	std::string getModel() const;
	int getYear() const;
	std::string getVersion() const;
	std::string getEngine() const;
	std::string getVin() const;
	void setMark(std::string& _mark);
	void setModel(std::string& _model);
	void setYear(int & _year);
	void setVersion(std::string& _version);
	void setEngine(std::string& _engine);
	void setVin(std::string& _vin);

	void setIntervalOil_km(int _oilKm);
	void setIntervalTiming_km(int _timingKm);
	void setIntervalOil(int _day, int _month, int _year);
	void setIntervalTiming(int _day, int _month, int _year);
	void setIntervalOther(int _id, int _day, int _month, int _year);

	void addService(std::unique_ptr<Service> service);
	void addNotification(std::unique_ptr<Notification> notification);
	void removeService(int _id);
	void removeNotification(std::string _type);
	void removeIntervalOther(int _id);
	void removeIntervalOil();
	void removeIntervalTiming();

};

#endif