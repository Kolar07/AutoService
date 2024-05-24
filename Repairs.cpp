#include "MainView.h"
#include <iostream>
#include "Service.h"
#include <vector>
#include "ServiceOil.h"

int main() {
	//MainView window;
	//window.loop();
	
	//Service a(Service::oil,15000);
	//a.print();
	std::vector<std::unique_ptr<Service>> services;
	std::unique_ptr<Service> a = std::make_unique<ServiceOil>(200, "sad", "dasd", "frfrs", "tgth");
	services.push_back(std::make_unique<ServiceOil>(200, "sad", "dasd", "frfrs", "tgth"));
	services[0]->print();
}

//views are gonna inherit after mainview
//create a class which will control the views display with unique ptr
//control GUI