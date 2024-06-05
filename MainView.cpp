#include "MainView.h"
#include "VehicleVisualisation.h"
#include "Vehicle.h"

void MainView::loop() {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "AutoService");
    
    Vehicle vehicle("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN");
    sf::Font font;
    font.loadFromFile("Montserrat-Bold.ttf");
    VehicleVisualisation visu(vehicle,font);
    visu.setPosition(20,20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(visu);
        window.display();
        
    }
}