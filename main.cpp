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

	Vehicle vehicle("asdasd","asdasd",2001,"sdad","asdad","VIN");
	Date date1(10,10,2020);
	Date date2(12, 12, 2023);
	//std::unique_ptr<Notification> notification1 = std::make_unique<NotificationOil>("green",date1);
	//std::unique_ptr<Notification> notification2 = std::make_unique<NotificationTiming>("red",date2);
	
	std::unique_ptr<Service> service1 = std::make_unique<ServiceTiming>(15616, 10,4,2024,0,3,0,"cdsc");
	std::unique_ptr<Service> service2 = std::make_unique<ServiceOil>(1561,3,6,2024, 0, 0, 0,"sdczdc","cdvzvd","dsfsdf","fdescd");

	std::unique_ptr<Notification> notification3 = std::make_unique<NotificationTiming>(service1->getDate(), service1->getDueDate());
	std::unique_ptr<Notification> notification4 = std::make_unique<NotificationOil>(service2->getDate(), service2->getDueDate());

	//Interval interval(0, 6, 0);
	vehicle.setIntervalOther(service1->getID(), 0, 6, 0);
	vehicle.removeIntervalOther(service1->getID());

	notification3->updateNotificationTime();

	VehicleContainer container;

	//vehicle.addNotification(std::move(notification1));
	//vehicle.addNotification(std::move(notification2));
	vehicle.addService(std::move(service1));
	vehicle.addService(std::move(service2));

	container.addVehicle(vehicle);
	container.findVehicleByVin("VIN");
	container.removeVehicle("VIN");
	//vehicle.removeNotification("Oil");
	//vehicle.removeNotification("Timing");
	//vehicle.removeService(1);
	//vehicle.removeService(2);


	std::unique_ptr<Service> serv = std::make_unique<ServiceTiming>();

}

//views are gonna inherit after mainview
//create a class which will control the views display with unique ptr
//control GUI