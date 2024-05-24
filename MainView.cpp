#include "MainView.h"

void MainView::loop() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Repairs");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}