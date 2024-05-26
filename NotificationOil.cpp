#include "NotificationOil.h"

NotificationOil::NotificationOil() {};

NotificationOil::NotificationOil(std::string _status, Date _dueDate) :Notification(_status, _dueDate) {}

bool NotificationOil::operator==(const NotificationOil& obj) {
	return this->getType() == obj.getType();
}

std::string NotificationOil::getType() const {
	return "Oil";
}

 void NotificationOil::print() {
	std::cout <<"Notification type: "<<getType()<< ", Notification status: " << getStatus() << ", next service: ";
	Notification::getDueDate().display();
	}

 std::unique_ptr<Notification> NotificationOil::clone() const {
	 return std::make_unique<NotificationOil>(*this);
 }