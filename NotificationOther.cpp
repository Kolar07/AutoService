#include "NotificationOther.h"

NotificationOther::NotificationOther() {};

NotificationOther::NotificationOther(std::string _status, Date _dueDate) :Notification(_status, _dueDate) {}

bool NotificationOther::operator==(const NotificationOther& obj) {
	return specifiedType == obj.specifiedType;
}

std::string NotificationOther::getType() const {
	return "Other";
}

std::string NotificationOther::getSpecifiedType() {
	return specifiedType;
}

void NotificationOther::print() {
	std::cout << "Notification type: " << getType() << ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
}

std::unique_ptr<Notification> NotificationOther::clone() const {
	return std::make_unique<NotificationOther>(*this);
}