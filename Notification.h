#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"

class Notification {
private:
	//std::string type;
	std::string status;
	//time_t dueMileage;
	Date dueDate;
public:
	Notification();
	Notification(Date _dueDate);
	std::string getType();
	std::string getStatus();
	//time_t getDueMileage();
	Date getDueDate();
	void setDueDate(Date _dueDate);
};


#endif