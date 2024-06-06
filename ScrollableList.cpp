#include "ScrollableList.h"

void ScrollableList::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseWheelScrolled) {
        scrollAmount -= event.mouseWheelScroll.delta * ITEM_HEIGHT;
        scrollAmount = std::clamp(scrollAmount, 0.0f, maxScroll);
        updateScrollbar();
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (scrollbar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                isDragging = true;
                dragOffset = event.mouseButton.y - scrollbar.getPosition().y;
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
        }
    }
    else if (event.type == sf::Event::MouseMoved) {
        if (isDragging) {
            float newScrollBarPosition = event.mouseMove.y - dragOffset;
            newScrollBarPosition = std::clamp(newScrollBarPosition, position.y, position.y + size.y - scrollbar.getSize().y);
            scrollbar.setPosition(scrollbar.getPosition().x, newScrollBarPosition);
            float scrollPercent = (newScrollBarPosition - position.y) / (size.y - scrollbar.getSize().y);
            scrollAmount = scrollPercent * maxScroll;
        }
    }
}

void ScrollableList::update() {
    // Update the viewport and view reset
    view.setViewport(sf::FloatRect(position.x / 1600, position.y / 800, size.x / 1600, size.y / 800));
    view.reset(sf::FloatRect(0, scrollAmount, size.x, size.y));
}

void ScrollableList::draw(sf::RenderWindow& window) {
    window.setView(view);

    for (size_t i = 0; i < listItems.size(); ++i) {
        // Positioning each item according to scrollAmount
        listItems[i].setPosition(0, 0 + i * ITEM_HEIGHT);
        listItems[i].draw(window);
    }

    window.setView(window.getDefaultView());
    window.draw(scrollbar);
}

void ScrollableList::updateScrollbar() {
    float scrollPercent = scrollAmount / maxScroll;
    scrollBarPosition = position.y + scrollPercent * (size.y - scrollbar.getSize().y);
    scrollbar.setPosition(scrollbar.getPosition().x, scrollBarPosition);
}

ScrollableList::ScrollableList(float x, float y, float width, float height, const std::vector<VehicleVisualisation> &items)
    : position(x, y), size(width, height), view(sf::FloatRect(x, y, width, height)),
    isDragging(false), scrollBarPosition(y), scrollBarHeight(height* (height / (ITEM_HEIGHT * items.size()))),
    listItems(items) {

    scrollAmount = 0;
    maxScroll = std::max(0.0f, ITEM_HEIGHT * items.size() - height);

    scrollbar.setSize(sf::Vector2f(SCROLLBAR_WIDTH, scrollBarHeight));
    scrollbar.setPosition(x + width - SCROLLBAR_WIDTH, scrollBarPosition);
    scrollbar.setFillColor(sf::Color(200, 200, 200));
}
