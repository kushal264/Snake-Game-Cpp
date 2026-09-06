#include "Snake.h"

namespace
{
    constexpr int CELL_SIZE = 25;
}

Snake::Snake()
{
    reset();
}

void Snake::reset()
{
    body.clear();

    body.push_back({10, 10});
    body.push_back({9, 10});
    body.push_back({8, 10});

    direction = {1, 0};
}

void Snake::changeDirection(sf::Vector2i newDirection)
{
    if (newDirection.x == -direction.x &&
        newDirection.y == -direction.y)
    {
        return;
    }

    direction = newDirection;
}

void Snake::move()
{
    const sf::Vector2i newHead = body.front() + direction;

    body.insert(body.begin(), newHead);
    body.pop_back();
}

void Snake::grow()
{
    body.push_back(body.back());
}

void Snake::draw(sf::RenderWindow& window)
{
    sf::RectangleShape segment({
        static_cast<float>(CELL_SIZE - 2),
        static_cast<float>(CELL_SIZE - 2)
    });

    for (std::size_t i = 0; i < body.size(); ++i)
    {
        segment.setPosition({
            static_cast<float>(body[i].x * CELL_SIZE + 1),
            static_cast<float>(body[i].y * CELL_SIZE + 1)
        });

        segment.setFillColor(
            i == 0
                ? sf::Color(50, 200, 50)
                : sf::Color(30, 150, 30)
        );

        window.draw(segment);
    }
}

bool Snake::checkSelfCollision() const
{
    const sf::Vector2i head = body.front();

    for (std::size_t i = 1; i < body.size(); ++i)
    {
        if (body[i] == head)
            return true;
    }

    return false;
}

bool Snake::contains(const sf::Vector2i& position) const
{
    for (const auto& segment : body)
    {
        if (segment == position)
            return true;
    }

    return false;
}

sf::Vector2i Snake::getHead() const
{
    return body.front();
}

const std::vector<sf::Vector2i>& Snake::getBody() const
{
    return body;
}
