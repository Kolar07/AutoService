#ifndef NOTIFICATION_OTHER_H_
#define NOTIFICATION_OTHER_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"
#include "Notification.h"

class NotificationOther : public Notification {
private:
	//std::string type = "Other";
	std::string specifiedType = "";

public:
	NotificationOther();
	NotificationOther(/*std::string _status*/Date date, Date _dueDate);
	bool operator==(const NotificationOther& obj);
	bool operator!=(const NotificationOther& obj);
	std::string getType() const override;
	std::string getSpecifiedType();
	virtual void print() override;
	virtual std::unique_ptr<Notification> clone() const override;
};


#endif