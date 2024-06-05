#ifndef SCROLLABLE_LIST_H
#define SCROLLABLE_LIST_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "VehicleVisualisation.h"

class ScrollableList {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::vector<VehicleVisualisation> items;
    sf::View view;
    sf::RectangleShape scrollbar;
    float scrollAmount;
    float maxScroll;
    bool isDragging;
    float dragOffset;
    float scrollBarPosition;
    float scrollBarHeight;

    void updateScrollbar();

public:
    ScrollableList(float x, float y, float _width, float _height,float _itemHeight, std::vector<VehicleVisualisation> &_items);
    void handleEvent(const sf::Event _event);
    void update();
    void draw(sf::RenderWindow &_window);
};

#endif