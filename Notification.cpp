#include "Notification.h"

//std::string Notification::getType() {
//	return type;
//}

Notification::Notification() {};

Notification::Notification(Date _dueDate):dueDate(_dueDate) {}

std::string Notification::getStatus() {
	return status;
}

Date Notification::getDueDate() {
	return dueDate;
}

void Notification::setDueDate(Date _dueDate) {
	dueDate = _dueDate;
}