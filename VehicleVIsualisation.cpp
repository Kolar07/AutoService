#include "VehicleVisualisation.h"

void VehicleVisualisation::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
    _target.draw(background, _states);
    _target.draw(mark, _states);
    _target.draw(model, _states);
    _target.draw(vin, _states);
    _target.draw(year, _states);
}

VehicleVisualisation::VehicleVisualisation(const Vehicle& _vehicle, sf::Font &_font) :vehicle(_vehicle){
    background.setSize(sf::Vector2f(800, 100));
    background.setFillColor(sf::Color(50, 50, 50));

    mark.setFont(_font);
    mark.setCharacterSize(20);
    mark.setFillColor(sf::Color::Black);
    //mark.setPosition(50,50);
    mark.setString(_vehicle.getMark());

    model.setFont(_font);
    model.setCharacterSize(20);
    model.setFillColor(sf::Color::Black);
    model.setPosition(50, 50);
    model.setString(_vehicle.getModel());

    vin.setFont(_font);
    vin.setCharacterSize(20);
    vin.setFillColor(sf::Color::Black);
    vin.setPosition(50, 50);
    vin.setString(_vehicle.getVin());

    year.setFont(_font);
    year.setCharacterSize(20);
    year.setFillColor(sf::Color::Black);
    year.setPosition(50, 50);
    year.setString(std::to_string(_vehicle.getYear()));
}

void VehicleVisualisation::setPosition(float x, float y) {
    background.setPosition(x, y);
    mark.setPosition(x + 10, y + 10);
    model.setPosition(x += mark.getLocalBounds().width+20, y + 10);
    vin.setPosition(x += model.getLocalBounds().width+20, y + 10);
    year.setPosition(x += vin.getLocalBounds().width+20, y + 10);
}