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
	ServiceOther(int mileage_, std::string _service);
	//std::ostream& operator<<(const std::ostream& os);

	virtual void print() override;

	std::string getType();
	std::string getOther();
	virtual std::unique_ptr<Service> clone() const override;

};


#endif