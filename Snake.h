#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Snake
{
private:
    std::vector<sf::Vector2i> body;
    sf::Vector2i direction;

public:
    Snake();

    void reset();
    void changeDirection(sf::Vector2i newDirection);
    void move();
    void grow();
    void draw(sf::RenderWindow& window);

    bool checkSelfCollision() const;
    bool contains(const sf::Vector2i& position) const;

    sf::Vector2i getHead() const;
    const std::vector<sf::Vector2i>& getBody() const;
};
