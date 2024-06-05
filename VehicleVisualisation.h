#ifndef VEHICLE_VISU_H_
#define VEHICLE_VISU_H_

#include <SFML/Graphics.hpp>
#include "Vehicle.h"

class VehicleVisualisation : public sf::Drawable {
private:
	const Vehicle& vehicle;
	sf::RectangleShape background;
	sf::Text mark;
	sf::Text model;
	sf::Text vin;
	sf::Text year;
	
public:
	//VehicleVisualisation();
	VehicleVisualisation(const Vehicle &_vehicle, sf::Font &_font);
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
	void setPosition(float x, float y);



};


#endif