#ifndef SERVICE_TIMING_H_
#define SERVICE_TIMING_H_

#include <iostream>
#include <vector>
#include <ostream>
#include "Service.h"

class ServiceTiming : public Service {

private:
	std::string type = "Timing";
	std::string timing;

public:
	ServiceTiming();
	ServiceTiming(int _mileage, int _day, int _month, int _year, std::string _timing);
	std::ostream& operator<<(const std::ostream& os);

	virtual void print() override;

	std::string getType();
	std::string getTiming();
	virtual std::unique_ptr<Service> clone() const override;

};


#endif