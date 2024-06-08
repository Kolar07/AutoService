#ifndef SCROLLABLE_LIST_H
#define SCROLLABLE_LIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "VehicleVisualisation.h"

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 800;
<<<<<<< HEAD
=======
const int ITEM_HEIGHT = 100;
const int VISIBLE_ITEMS = 6;
>>>>>>> 860e36b8944ce6989e9f71236918a08b6576ca65
const int SCROLLBAR_WIDTH = 20;

class ScrollableList {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::vector<VehicleVisualisation> listItems;
    sf::Font font;
    sf::View view;
    sf::RectangleShape scrollbar;
    sf::RectangleShape headers;
    std::vector<sf::Text> labels;
    float scrollAmount;
    float maxScroll;
    bool isDragging;
    float dragOffset;
    float scrollBarPosition;
    float scrollBarHeight;


    void updateScrollbar();

public:
<<<<<<< HEAD
    ScrollableList(float x, float y, float width, float height, const std::vector<VehicleVisualisation> &items, sf::Font &font);
    void handleEvent(const sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
    void setLabels(float x, float y,sf::Font &font);
=======
    ScrollableList(float x, float y, float width, float height, const std::vector<VehicleVisualisation> &items);
    void handleEvent(const sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
>>>>>>> 860e36b8944ce6989e9f71236918a08b6576ca65
};

#endif