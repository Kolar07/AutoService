#include "NotificationOther.h"

NotificationOther::NotificationOther() {};

NotificationOther::NotificationOther(std::string _status, Date _dueDate) :Notification(_status, _dueDate) {}

std::string NotificationOther::getType() {
	return type;
}

void NotificationOther::print() {
	std::cout << "Notification type: " << type << ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
}