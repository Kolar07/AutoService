#ifndef NOTIFICATION_TIMING_H_
#define NOTIFICATION_TIMING_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"
#include "Notification.h"

class NotificationTiming : public Notification {
private:
	std::string type = "Timing";

public:
	NotificationTiming();
	NotificationTiming(std::string _status, Date _dueDate);
	std::string getType();
	virtual void print() override;
};


#endif