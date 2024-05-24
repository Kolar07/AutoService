#ifndef NOTIFICATION_VISUALISATION_H_
#define NOTIFICATION_VISUALISATION_H_

#include <iostream>
#include "Notification.h"
#include <SFML/Graphics.hpp>

class NotificationVisualisation {
	std::unique_ptr<Notification> notification;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;
};

#endif