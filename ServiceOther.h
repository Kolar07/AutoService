#ifndef SERVICE_OTHER_H_
#define SERVICE_OTHER_H_

#include <iostream>
#include <vector>
#include <ostream>
#include "Service.h"

class ServiceOther : public Service {

private:
	std::string type = "Other";
	std::string service;

public:
	ServiceOther();
	ServiceOther(int _mileage, int _day, int _month, int _year, std::string _service);
	ServiceOther(int _mileage, int _dayOfService, int _monthOfService, int _yearOfService, int _daysToNextService, int _monthsToNextService, int _yearsToNextService, std::string _service);
	//std::ostream& operator<<(const std::ostream& os);

	virtual void print() override;
	virtual std::unique_ptr<Service> clone() const override;

	std::string getType();
	std::string getOther();

};


#endif