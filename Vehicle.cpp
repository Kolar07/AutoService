#include "Vehicle.h"

Vehicle::Vehicle() {
	std::cout << "Vehicle constructor called" << std::endl;
}

Vehicle::Vehicle(std::string _mark, std::string _model, int _year, std::string _version, std::string _engine, std::string _vin) : mark(_mark),model(_model), year(_year),version(_version),engine(_engine),vin(_vin){
	std::cout << "Vehicle argument constructor called" << std::endl;
}

Vehicle::Vehicle(const Vehicle& other):mark(other.mark), model(other.model), year(other.year), version(other.version), engine(other.engine),vin(other.vin), intervalOil_km(other.intervalOil_km), intervalTiming_km(other.intervalTiming_km),intervalOil(other.intervalOil), intervalTiming(other.intervalTiming), intervalOtherMap(other.intervalOtherMap) {

	services.reserve(other.services.size());
	for (const auto& service : other.services) {
		services.push_back(service->clone());
	}

	notifications.clear();
	notifications.reserve(other.notifications.size());
	for (const auto& notification : other.notifications) {
		notifications.push_back(notification->clone());
	}
}

Vehicle::Vehicle(Vehicle&& other) noexcept :mark(std::move(other.mark)), model(std::move(other.model)), year(other.year),
version(std::move(other.version)), engine(std::move(other.engine)), vin(std::move(other.vin)),
intervalOil_km(other.intervalOil_km), intervalTiming_km(other.intervalTiming_km),
intervalOil(std::move(other.intervalOil)), intervalTiming(std::move(other.intervalTiming)),
intervalOtherMap(std::move(other.intervalOtherMap)), services(std::move(other.services)),
notifications(std::move(other.notifications)) {

	other.year = 0;
	other.intervalOil_km = 0;
	other.intervalTiming_km = 0;

}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	else {
		mark = std::move(other.mark);
		model = std::move(other.model);
		year = other.year;
		version = std::move(other.version);
		engine = std::move(other.engine);
		vin = std::move(other.vin);
		intervalOil_km = other.intervalOil_km;
		intervalTiming_km = other.intervalTiming_km;
		intervalOil = std::move(other.intervalOil);
		intervalTiming = std::move(other.intervalTiming);
		intervalOtherMap = std::move(other.intervalOtherMap);

		other.year = 0;
		other.intervalOil_km = 0;
		other.intervalTiming_km = 0;
		return *this;
	}
}

bool Vehicle::operator==(const Vehicle& obj) const {
	return this->vin == obj.vin;
}

Vehicle &Vehicle::operator=(const Vehicle& obj) {
	if (this == &obj) {
		return *this;
	}
	else {
		mark = obj.mark;
		model = obj.model;
		year = obj.year;
		version = obj.version;
		engine = obj.engine;
		vin = obj.vin;
		intervalOil_km = obj.intervalOil_km;
		intervalTiming_km = obj.intervalTiming_km;
		intervalOil = obj.intervalOil;
		intervalTiming = obj.intervalTiming;
		intervalOtherMap = obj.intervalOtherMap;
		//services = std::move(obj.services);
		//notifications = std::move(obj.notifications); 
		services.clear();
		services.reserve(obj.services.size());
		for (const auto& service : obj.services) {
			services.push_back(service->clone());
		}

		notifications.clear();
		notifications.reserve(obj.notifications.size());
		for (const auto& notification : obj.notifications) {
			notifications.push_back(notification->clone());
		}
		//add future intervals when done
		return *this;
	}
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

std::string Vehicle::get_vin() const {
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

void Vehicle::addService(std::unique_ptr<Service> service)  {
	services.push_back(std::move(service));
}

void Vehicle::addNotification(std::unique_ptr<Notification> notification) {
	notifications.push_back(std::move(notification));
}

void Vehicle::removeNotification(std::string _type) {
	auto it = std::find_if(notifications.begin(), notifications.end(), [_type](const std::unique_ptr<Notification>& notification) {
		return notification->getType() == _type;
		});

	if (it != notifications.end()) {
		notifications.erase(it);
	}
}

void Vehicle::removeService(int _id) {
	auto it = std::find_if(services.begin(), services.end(), [&_id](const std::unique_ptr<Service>& service) {
		return service->getID() == _id;
		});
	if (it != services.end()) {
		services.erase(it);
	}
}