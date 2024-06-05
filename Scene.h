#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() {}
    virtual void handleEvent(sf::Event event) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};


#endif