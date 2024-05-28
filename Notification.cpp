#include "Notification.h"

//std::string Notification::getType() {
//	return type;
//}

Notification::Notification() {};

Notification::Notification(Date _date, Date _dueDate):date(_date) {
	
	Date temp = _date;
	temp = temp.addYears(_dueDate.getYear());
	temp = temp.addMonths(_dueDate.getMonth());
	temp = temp.addDays(_dueDate.getDay());
	dueDate = temp;

	int between = _date.daysBetween(temp);
	if (between >= 60) status = "green";
	else if (between < 60 && between > 0) status = "yellow";
	else status = "red";
	std::cout << "Days to the next service: " << between <<", Status: "<<status<< std::endl;

}


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