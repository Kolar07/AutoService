#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <iostream>
#include <vector>
#include <time.h>

class Notification {
	std::string type;
	std::string status;
	time_t dueMileage;
	time_t dueDate;
};


#endif