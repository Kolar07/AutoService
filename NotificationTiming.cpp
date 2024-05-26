#include "NotificationTiming.h"

NotificationTiming::NotificationTiming() {};

NotificationTiming::NotificationTiming(std::string _status, Date _dueDate) :Notification(_status, _dueDate) {}

std::string NotificationTiming::getType() {
	return type;
}

void NotificationTiming::print() {
	std::cout << "Notification type: " << type << ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
}

std::unique_ptr<Notification> NotificationTiming::clone() const {
	return std::make_unique<NotificationTiming>(*this);
}