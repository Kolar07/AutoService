#include "VehicleContainer.h"

void VehicleContainer::addVehicle(Vehicle &_vehicle) {
	vehicles.push_back(std::move(_vehicle)); //program crashes, attempting to reference a deleted function
}

void VehicleContainer::removeVehicle(std::string _vin) {
	auto it = std::find_if(vehicles.begin(), vehicles.end(), [&_vin](const Vehicle& vehicle) {
		return vehicle.get_vin() == _vin;
		});
	if (it!=vehicles.end()) {
		vehicles.erase(it);
	}
}