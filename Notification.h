#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"

class Notification {
private:
	std::string status;
	Date dueDate;
public:
	Notification();
	Notification(std::string _status,Date _dueDate);
	virtual bool operator==(const Notification& other) const;

	virtual std::string getType() const = 0;
	std::string getStatus();
	Date getDueDate();
	void setDueDate(Date _dueDate);
	virtual void print() =0;
	virtual std::unique_ptr<Notification> clone() const = 0;
};


#endif