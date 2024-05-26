#include "Notification.h"

//std::string Notification::getType() {
//	return type;
//}

Notification::Notification() {};

Notification::Notification(std::string _status, Date _dueDate):status(_status), dueDate(_dueDate) {}


std::string Notification::getStatus() {
	return status;
}

Date Notification::getDueDate() {
	return dueDate;
}

void Notification::setDueDate(Date _dueDate) {
	dueDate = _dueDate;
}

bool Notification::operator==(const Notification& obj) const {
	return getType() == obj.getType();
}

//void Notification::print() const {
//	std::cout << "Notification status: " << status << ", next service: ";
//	dueDate.display();
//}