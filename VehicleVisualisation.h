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
	sf::Text version;
	sf::Text vin;
	sf::Text year;
	/*sf::Text intervalOil_km;
	sf::Text intervalTiming_km;
	sf::Text intervalOil;
	sf::Text intervalTiming;
	sf::Text year;*/
	//std::map<int, sf::Text> intervalOtherMap;
	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;
public:
	//VehicleVisualisation();
	VehicleVisualisation(const Vehicle &_vehicle, sf::Font &_font);

	void setPosition(float x, float y);



};


#endif