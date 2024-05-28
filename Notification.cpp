#include "Notification.h"

//std::string Notification::getType() {
//	return type;
//}

Notification::Notification() {};

Notification::Notification(Date _date, Date _dueDate):date(_date), dueDate(_dueDate) {}


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

bool Notification::operator!=(const Notification& obj) const {
	return getType() != obj.getType();
}

//void Notification::print() const {
//	std::cout << "Notification status: " << status << ", next service: ";
//	dueDate.display();
//}