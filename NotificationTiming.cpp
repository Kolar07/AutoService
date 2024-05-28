#include "NotificationTiming.h"

NotificationTiming::NotificationTiming() {};

NotificationTiming::NotificationTiming(Date _date, Date _dueDate) :Notification(_date, _dueDate) {}


bool NotificationTiming::operator==(const NotificationTiming& obj) {
	return getType() == obj.getType();
}

bool NotificationTiming::operator!=(const NotificationTiming& obj) {
	return getType() != obj.getType();
}

std::string NotificationTiming::getType() const {
	return "Timing";
}

void NotificationTiming::print() {
	std::cout << "Notification type: " << getType() << ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
}

std::unique_ptr<Notification> NotificationTiming::clone() const {
	return std::make_unique<NotificationTiming>(*this);
}