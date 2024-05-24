#include "MainView.h"
#include <iostream>
#include "Service.h"
#include <vector>
#include "ServiceOil.h"
#include "ServiceTiming.h"
#include "ServiceOther.h"

int main() {
	//MainView window;
	//window.loop();
	
	//Service a(Service::oil,15000);
	//a.print();
	std::vector<std::unique_ptr<Service>> services;
	services.push_back(std::make_unique<ServiceOil>(543453, "sad", "dasd", "frdfgfrs", "tgdfgth"));
	services.push_back(std::make_unique<ServiceOil>(2045340, "sdfsfd", "dadfgsd", "frdfgfrs", "tdfggth"));
	services.push_back(std::make_unique<ServiceOil>(20534350, "sgdfdfgad", "dafdgsd", "frfdfgrs", "tgdfgth"));
	services.push_back(std::make_unique<ServiceOil>(245300, "sfdgdfgad", "dasd", "frfrdfgs", "tdfggth"));
	services.push_back(std::make_unique<ServiceTiming>(354, "sdsfd"));
	services.push_back(std::make_unique<ServiceTiming>(345, "sdhjkhjkf"));
	services.push_back(std::make_unique<ServiceTiming>(453, "hkj"));
	services.push_back(std::make_unique<ServiceTiming>(453, "sdhjkhjksfd"));
	services.push_back(std::make_unique<ServiceOther>(5343, "sdhjkhjksfd"));
	services.push_back(std::make_unique<ServiceOther>(543, "fre"));
	services.push_back(std::make_unique<ServiceOther>(45343, "sdhjdfgdfdsrgkhjksfd"));
	services.push_back(std::make_unique<ServiceOther>(53453, "fdg"));
	
	for (int i = 0; i < services.size();i++) {
		services[i]->print();
	}
}

//views are gonna inherit after mainview
//create a class which will control the views display with unique ptr
//control GUI