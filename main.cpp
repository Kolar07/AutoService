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

	Vehicle vehicle;
	Date date1(10,10,2020);
	Date date2(12, 12, 2023);
	std::unique_ptr<Notification> notification1 = std::make_unique<NotificationOil>("green",date1);
	std::unique_ptr<Notification> notification2 = std::make_unique<NotificationTiming>("red",date2);
	
	std::unique_ptr<Service> service1 = std::make_unique<ServiceTiming>(15616, 20,0,0,"cdsc");
	std::unique_ptr<Service> service2 = std::make_unique<ServiceOil>(1561,0,5,0,"sdczdc","cdvzvd","dsfsdf","fdescd");

	vehicle.addNotification(std::move(notification1));
	vehicle.addNotification(std::move(notification2));
	vehicle.addService(std::move(service1));
	vehicle.addService(std::move(service2));

	vehicle.removeNotification("Oil");
	vehicle.removeNotification("Timing");
	vehicle.removeService(1);
	vehicle.removeService(2);


}

//views are gonna inherit after mainview
//create a class which will control the views display with unique ptr
//control GUI