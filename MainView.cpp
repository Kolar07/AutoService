#include "MainView.h"
#include "VehicleVisualisation.h"
#include "Vehicle.h"
#include "ScrollableList.h"
#include "VehicleContainer.h"

void MainView::loop() {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "AutoService");
    
    Vehicle vehicle1("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN1");
    Vehicle vehicle2("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN2");
    Vehicle vehicle3("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN3");
    Vehicle vehicle4("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN4");
    Vehicle vehicle5("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN5");
    Vehicle vehicle6("asdasdfsdfsdfssd", "asdasd", 2001, "sdad", "asdad", "VIN6");
    sf::Font font;
    font.loadFromFile("Montserrat-Bold.ttf");
    VehicleVisualisation visu1(vehicle1, font);
    VehicleVisualisation visu2(vehicle2, font);
    VehicleVisualisation visu3(vehicle3, font);
    VehicleVisualisation visu4(vehicle1, font);
    VehicleVisualisation visu5(vehicle1, font);
    VehicleVisualisation visu6(vehicle5, font);
    VehicleVisualisation visu7(vehicle6, font);
    VehicleVisualisation visu8(vehicle1, font);
    VehicleVisualisation visu9(vehicle1, font);
    
    std::vector<VehicleVisualisation> container;
    container.push_back(visu1);
    container.push_back(visu2);
    container.push_back(visu3);
    container.push_back(visu4);
    container.push_back(visu5);
    container.push_back(visu6);
    container.push_back(visu7);
    container.push_back(visu8);
    container.push_back(visu9);
    ScrollableList list(100, 150, 1000, ITEM_HEIGHT * VISIBLE_ITEMS, container);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            list.handleEvent(event);
        }

        list.update();

        window.clear(sf::Color::White);
        list.draw(window);
        window.display();
        
    }
}