#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
private:
	sf::RectangleShape button;
	sf::Text text;
public:
	Button() {}
	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textcolor);
	void setFont(sf::Font& font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setOutline(int thickness, sf::Color color);
	void setPosition(sf::Vector2f pos);
	void drawButton(sf::RenderWindow& window) const;
	bool isMouseOver(sf::RenderWindow& window);
	sf::Text returnText();
	sf::RectangleShape returnRectangle();
	void SetRectangle(sf::RectangleShape _shape);
	void SetText(sf::Text _text);
};