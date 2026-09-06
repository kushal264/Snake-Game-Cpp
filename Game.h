#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.h"

class Game
{
private:
    static constexpr int GRID_WIDTH = 32;
    static constexpr int GRID_HEIGHT = 24;
    static constexpr int CELL_SIZE = 25;

    sf::RenderWindow window;
    Snake snake;

    sf::Vector2i food;

    int score = 0;
    int highScore = 0;

    bool gameOver = false;
    bool paused = false;

    sf::Clock clock;
    float moveDelay = 0.15f;

public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    void spawnFood();
    void reset();

    bool checkWallCollision() const;
    void updateScore();

    void drawText(
        const sf::String& text,
        unsigned int size,
        sf::Vector2f position
    );
};
