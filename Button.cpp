#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textcolor) {
	text.setString(t);
	text.setFillColor(textcolor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(bgcolor);
}

void Button::setFont(sf::Font& font) {
	text.setFont(font);
}

void Button::setBackColor(sf::Color color) {
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	text.setFillColor(color);
}

void Button::setOutline(int thickness, sf::Color color) {
	button.setOutlineThickness(thickness);
	button.setOutlineColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);
	float xPos = ((pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2));
	float yPos = ((pos.y + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2));
	text.setPosition({ xPos, yPos });
}

void Button::drawButton(sf::RenderWindow& window) const {
	window.draw(button);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnxPosWidth = button.getPosition().x + button.getGlobalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getGlobalBounds().height;
	if (mouseX<btnxPosWidth && mouseX>btnPosX && mouseY<btnyPosHeight && mouseY>btnPosY) {
		return true;
	}
	return false;
}
sf::Text Button::returnText() {
	return text;
}
//jkghl
sf::RectangleShape Button::returnRectangle() {
	return button;
}

void Button::SetRectangle(sf::RectangleShape _shape) {
	button = _shape;
}

void Button::SetText(sf::Text _text) {
	text = _text;
}