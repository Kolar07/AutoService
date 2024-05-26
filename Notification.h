#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"

class Notification {
private:
	std::string status;
	//time_t dueMileage;
	Date dueDate;
public:
	Notification();
	Notification(std::string _status,Date _dueDate);

	std::string getType();
	std::string getStatus();
	//time_t getDueMileage();
	Date getDueDate();
	void setDueDate(Date _dueDate);
	virtual void print() =0;
	virtual std::unique_ptr<Notification> clone() const = 0;
};


#endif