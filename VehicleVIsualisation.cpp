#include "VehicleVisualisation.h"

void VehicleVisualisation::draw(sf::RenderWindow &_window) const {
    _window.draw(background);
    _window.draw(mark);
    _window.draw(model);
    _window.draw(vin);
    _window.draw(year);
    moreInfo.drawButton(_window);
}

std::string VehicleVisualisation::wrapText(const std::string& text, float maxWidth, const sf::Font& font, unsigned int charSize) {
    std::string wrapped;
    std::string line;
    float width = 0.0f;
    float lineHeight = 0.0f;
    float maxHeight = 15.0;

    for (char c : text) {
        line += c;
        sf::Text temp(line, font, charSize);
        sf::FloatRect bounds = temp.getLocalBounds();

        if (bounds.width > maxWidth) {
            wrapped += '\n' + std::string(1, c);
            line = std::string(1, c);
            maxHeight += lineHeight;
            lineHeight = temp.getLocalBounds().height;
        }
        else {
            wrapped += c;
            lineHeight = std::max(lineHeight, bounds.height);
        }
    }

    maxHeight += lineHeight;

    if (maxHeight > background.getSize().y-15) {
        float newY = maxHeight + 30;
        float X = background.getSize().x;
        background.setSize(sf::Vector2f(X, newY));
    }

    return wrapped;
}

VehicleVisualisation::VehicleVisualisation(const Vehicle& _vehicle, sf::Font &_font) :vehicle(_vehicle) {

    background.setSize(sf::Vector2f(1000, 100));
    background.setFillColor(sf::Color(100, 100, 100));
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color::Black);

    mark.setFont(_font);
    mark.setCharacterSize(20);
    mark.setFillColor(sf::Color::Black);
    mark.setPosition(50, 50);
    mark.setString(wrapText(_vehicle.getMark(),150,_font,20));


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

    moreInfo = Button("more info", {70, 20}, 10, sf::Color::Black, sf::Color::White);
    moreInfo.setFont(_font);

}

void VehicleVisualisation::setPosition(float x, float y) {
    background.setPosition(x, y);

    vin.setPosition(x + 10, y + 10);
    mark.setPosition(x + 250, y + 10);
    model.setPosition(x + 500, y + 10);
    year.setPosition(x + 800, y + 10);
    moreInfo.setPosition({ x + 900,y + 15 });
}

float VehicleVisualisation::getBackgroundHeight() const{
    return background.getSize().y;
}