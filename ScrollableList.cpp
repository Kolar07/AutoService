#include "ScrollableList.h"

void ScrollableList::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseWheelScrolled) {
        scrollAmount -= event.mouseWheelScroll.delta * 50;

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
    view.setViewport(sf::FloatRect(position.x / 1600, position.y / 800, size.x / 1600, size.y / 800));
    view.reset(sf::FloatRect(0, scrollAmount, size.x, size.y));
}

void ScrollableList::draw(sf::RenderWindow& window) {
    window.setView(view);

    float currentY = 0;
    for (size_t i = 0; i < listItems.size(); ++i) {
        listItems[i].setPosition(0, currentY);
        listItems[i].draw(window);
        currentY += listItems[i].getBackgroundHeight();
    }
        window.setView(window.getDefaultView());
        window.draw(scrollbar);
        window.draw(headers);

        for (const auto& label : labels) {
            window.draw(label);
        }
}

void ScrollableList::updateScrollbar() {
    float scrollPercent = scrollAmount / maxScroll;
    scrollBarPosition = position.y + scrollPercent * (size.y - scrollbar.getSize().y);
    scrollbar.setPosition(scrollbar.getPosition().x, scrollBarPosition);
}

ScrollableList::ScrollableList(float x, float y, float width, float height, const std::vector<VehicleVisualisation> &items, sf::Font &font)
    : position(x, y), size(width, height), view(sf::FloatRect(x, y, width, height)),
    isDragging(false), scrollBarPosition(y),listItems(items) {

    scrollAmount = 0;
    float totalHeight = 0;
    for (const auto& item : items) {
        totalHeight += item.getBackgroundHeight();
    }
    maxScroll = std::max(0.0f, totalHeight - height);

    scrollbar.setSize(sf::Vector2f(SCROLLBAR_WIDTH, height*(height/totalHeight)));
    scrollbar.setPosition(x + width - SCROLLBAR_WIDTH, scrollBarPosition);
    scrollbar.setFillColor(sf::Color(200, 200, 200));

    headers.setSize(sf::Vector2f(width, 25));
    headers.setPosition(x, y-25);
    headers.setFillColor(sf::Color(200, 200, 200));

    setLabels(x, y,font);
}

void ScrollableList::setLabels(float x, float y, sf::Font& font) {
    sf::Text label1;

    label1.setFont(font);
    label1.setCharacterSize(20);
    label1.setFillColor(sf::Color::Black);
    label1.setPosition(x + 10, y - 25);
    label1.setString("VIN");
    labels.push_back(label1);

    sf::Text label2;

    label2.setFont(font);
    label2.setCharacterSize(20);
    label2.setPosition(x + 200, y - 25);
    label2.setFillColor(sf::Color::Black);
    label2.setString("Mark");
    labels.push_back(label2);

    sf::Text label3;

    label3.setFont(font);
    label3.setCharacterSize(20);
    label3.setPosition(x + 400, y - 25);
    label3.setFillColor(sf::Color::Black);
    label3.setString("Model");
    labels.push_back(label3);

    sf::Text label4;

    label4.setFont(font);
    label4.setCharacterSize(20);
    label4.setPosition(x + 800, y - 25);
    label4.setFillColor(sf::Color::Black);
    label4.setString("VIN");
    labels.push_back(label4);
}