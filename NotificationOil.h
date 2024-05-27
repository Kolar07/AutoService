#ifndef NOTIFICATION_OIL_H_
#define NOTIFICATION_OIL_H_

#include <iostream>
#include <vector>
#include <time.h>
#include "Date.h"
#include "Notification.h"

class NotificationOil : public Notification {
private:
	//std::string type = "Oil";

public:
	NotificationOil();
	NotificationOil(std::string _status, Date _dueDate);
	bool operator==(const NotificationOil& obj);
	bool operator!=(const NotificationOil& obj);

	std::string getType() const override;
	virtual void print() override;
	virtual std::unique_ptr<Notification> clone() const override;
};


#endif