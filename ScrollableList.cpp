#include "ScrollableList.h"

ScrollableList::ScrollableList(float x, float y, float _width, float _height, float _itemHeight, std::vector<VehicleVisualisation> &_items) :position(x, y), size(_width, _height), view(sf::FloatRect(x, y, _width, _height)), isDragging(false), scrollBarPosition(y), scrollBarHeight(_height* (_height / (_itemHeight * _items.size()))) {

	scrollAmount = 0;
	maxScroll = std::max(0.0f, _itemHeight* items.size() - _height);
	scrollbar.setFillColor(sf::Color(200, 200, 200));
	scrollbar.setPosition(x+_width-20,scrollBarPosition);
	scrollbar.setSize(sf::Vector2f(20,scrollBarHeight));

}