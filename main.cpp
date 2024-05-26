#include "MainView.h"
#include <iostream>
#include "Service.h"
#include <vector>
#include "ServiceOil.h"
#include "ServiceTiming.h"
#include "ServiceOther.h"
#include "Date.h"
#include "Notification.h"
#include "NotificationOil.h"
#include "NotificationOther.h"
#include "NotificationTiming.h"
#include "Vehicle.h"
#include "VehicleContainer.h"

int main() {
	
	/*VehicleContainer container;
	Vehicle vehicle;
	std::unique_ptr<Service> service = std::make_unique<ServiceOil>(543453, 10, 10, 2020, "sad", "dasd", "frdfgfrs", "tgdfgth");
	std::unique_ptr<Notification> notification = std::make_unique<NotificationOil>();
	vehicle.addService(std::move(service));
	vehicle.addNotification(std::move(notification));
	container.addVehicle(vehicle);
	
	return 0;*/

	std::unique_ptr<Notification> notification1 = std::make_unique<NotificationOil>();
	std::unique_ptr<Notification> notification2 = std::make_unique<NotificationTiming>();
	std::unique_ptr<Notification> notification3 = std::make_unique<NotificationOil>();
	std::unique_ptr<Notification> notification4 = std::make_unique<NotificationOther>();

	std::cout << notification1->getType() << std::endl;
	std::cout << notification3->getType() << std::endl;

	if (*notification1 == *notification3) std::cout << "GITARA TRUE" << std::endl;
	//if (*notification2 != *notification4) std::cout << "GITARA FALSE" << std::endl;
}

//views are gonna inherit after mainview
//create a class which will control the views display with unique ptr
//control GUI