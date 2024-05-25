#include "NotificationOil.h"

NotificationOil::NotificationOil() {};

NotificationOil::NotificationOil(std::string _status, Date _dueDate) :Notification(_status, _dueDate) {}

std::string NotificationOil::getType() {
	return type;
}

 void NotificationOil::print() {
	std::cout <<"Notification type: "<<type<< ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
	}