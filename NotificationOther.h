#ifndef NOTIFICATION_OTHER_H_
#define NOTIFICATION_OTHER_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"
#include "Notification.h"

class NotificationOther : public Notification {
private:
	std::string type = "Other";

public:
	NotificationOther();
	NotificationOther(std::string _status, Date _dueDate);
	std::string getType();
	virtual void print() override;
	virtual std::unique_ptr<Notification> clone() const override;
};


#endif