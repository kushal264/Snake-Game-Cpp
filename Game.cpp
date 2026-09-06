#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <optional>
#include <iostream>

namespace
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
}

Game::Game()
    : window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Snake Game"
      )
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    window.setFramerateLimit(60);
    spawnFood();
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();

        if (!gameOver && !paused)
            update();

        render();
    }
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
            continue;
        }

        if (const auto* key =
                event->getIf<sf::Event::KeyPressed>())
        {
            if (key->scancode == sf::Keyboard::Scancode::Escape)
            {
                window.close();
            }
            else if (key->scancode == sf::Keyboard::Scancode::P &&
                     !gameOver)
            {
                paused = !paused;
            }
            else if (gameOver &&
                     key->scancode == sf::Keyboard::Scancode::Enter)
            {
                reset();
            }
            else if (!gameOver)
            {
                if (key->scancode == sf::Keyboard::Scancode::Up ||
                    key->scancode == sf::Keyboard::Scancode::W)
                {
                    snake.changeDirection({0, -1});
                }
                else if (
                    key->scancode == sf::Keyboard::Scancode::Down ||
                    key->scancode == sf::Keyboard::Scancode::S)
                {
                    snake.changeDirection({0, 1});
                }
                else if (
                    key->scancode == sf::Keyboard::Scancode::Left ||
                    key->scancode == sf::Keyboard::Scancode::A)
                {
                    snake.changeDirection({-1, 0});
                }
                else if (
                    key->scancode == sf::Keyboard::Scancode::Right ||
                    key->scancode == sf::Keyboard::Scancode::D)
                {
                    snake.changeDirection({1, 0});
                }
            }
        }
    }
}

void Game::update()
{
    if (clock.getElapsedTime().asSeconds() < moveDelay)
        return;

    clock.restart();

    snake.move();

    if (checkWallCollision() || snake.checkSelfCollision())
    {
        gameOver = true;

        if (score > highScore)
            highScore = score;

        return;
    }

    if (snake.getHead() == food)
    {
        snake.grow();
        ++score;

        updateScore();
        spawnFood();
    }
}

bool Game::checkWallCollision() const
{
    const sf::Vector2i head = snake.getHead();

    return head.x < 0 ||
           head.x >= GRID_WIDTH ||
           head.y < 0 ||
           head.y >= GRID_HEIGHT;
}

void Game::spawnFood()
{
    do
    {
        food.x = std::rand() % GRID_WIDTH;
        food.y = std::rand() % GRID_HEIGHT;
    }
    while (snake.contains(food));
}

void Game::updateScore()
{
    moveDelay = 0.15f - (score / 5) * 0.01f;

    if (moveDelay < 0.05f)
        moveDelay = 0.05f;

    if (score > highScore)
        highScore = score;

    std::cout << "Score: " << score
              << " | High Score: " << highScore << '\n';
}

void Game::reset()
{
    snake.reset();

    score = 0;
    moveDelay = 0.15f;
    gameOver = false;
    paused = false;

    clock.restart();
    spawnFood();
}

void Game::drawText(
    const sf::String& text,
    unsigned int size,
    sf::Vector2f position)
{
    // Text rendering is intentionally omitted until a font is placed
    // in assets/fonts. The game remains fully playable without it.
    (void)text;
    (void)size;
    (void)position;
}

void Game::render()
{
    window.clear(sf::Color(20, 20, 20));

    sf::CircleShape foodShape(
        static_cast<float>(CELL_SIZE / 2 - 2)
    );

    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition({
        static_cast<float>(food.x * CELL_SIZE + 2),
        static_cast<float>(food.y * CELL_SIZE + 2)
    });

    window.draw(foodShape);
    snake.draw(window);

    window.display();
}
