#ifndef VEHICLE_VISU_H_
#define VEHICLE_VISU_H_

#include <SFML/Graphics.hpp>
#include "Vehicle.h"
#include "Button.h"

class VehicleVisualisation {
private:
	const Vehicle& vehicle;
	sf::RectangleShape background;
	Button moreInfo;
	sf::Text mark;
	sf::Text model;
	sf::Text vin;
	sf::Text year;
	
public:
	//VehicleVisualisation();
	VehicleVisualisation(const Vehicle &_vehicle, sf::Font &_font);
	//VehicleVisualisation(std::string _mark, std::string _model, std::string _vin, int _year, sf::Font &_font);
	void draw(sf::RenderWindow &_window) const;
	void setPosition(float x, float y);
	std::string wrapText(const std::string& text, float maxWidth, const sf::Font& font, unsigned int charSize);
	float getBackgroundHeight() const;


};


#endif