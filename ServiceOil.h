#ifndef SERVICE_OIL_H_
#define SERVICE_OIL_H_

#include <iostream>
#include <vector>
#include <ostream>
#include "Service.h"

class ServiceOil : public Service {

private:
	std::string type = "Oil";
	std::string oil;
	std::string oilFilter;
	std::string airFilter;
	std::string cabinFilter;

public:
	ServiceOil(int mileage_,std::string _oil, std::string _oilFilter, std::string _airFilter, std::string _cabinFilter);
	//std::ostream& operator<<(const std::ostream& os);

	virtual void print() override;

	std::string getType();
	std::string getOil();
	std::string getOilFilter();
	std::string getAirFilter();
	std::string getCabinFilter();

};


#endif