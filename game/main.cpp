#include "fighters.h"
#include "screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;
constexpr unsigned MAX_FPS = 90;

void createWindow(sf::RenderWindow &window)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(
        sf::VideoMode::getDesktopMode(),
        "Tekken-8", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(MAX_FPS);
}

void handleEvents(sf::RenderWindow &window, Screen &screen, Fighter1 &fighter1, Fighter2 &fighter2)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        updateGameState(event, screen, fighter1, fighter2);
    }
}

void update(sf::Clock &clock, Fighter1 &fighter1, Fighter2 &fighter2)
{
    const float elapsedTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    updateFighter1(fighter1, elapsedTime, WINDOW_WIDTH);
    updateFighter2(fighter2, elapsedTime, WINDOW_WIDTH);
}

void renderStart(sf::RenderWindow &window, Screen &screen)
{
    window.clear();
    window.draw(screen.spriteStart);
    window.display();
}

void renderPlay(Screen &screen, sf::RenderWindow &window, Fighter1 &fighter1, Fighter2 &fighter2)
{
    window.clear();
    window.draw(screen.sprite);
    drawFighters(window, fighter1, fighter2);
    drawFightersHpBar(screen, window, fighter1.hp, fighter2.hp, fighter1.maxhp, fighter1.maxhp);
    window.display();
}

void renderPause(sf::RenderWindow &window, Screen &screen, Fighter1 &fighter1, Fighter2 &fighter2)
{
    window.clear();
    window.draw(screen.sprite);
    drawFighters(window, fighter1, fighter2);
    drawFightersHpBar(screen, window, fighter1.hp, fighter2.hp, fighter1.maxhp, fighter1.maxhp);
    window.draw(screen.spritePause);
    window.display();
}

void renderWin(sf::RenderWindow &window, Screen &screen)
{
    window.clear();
    window.draw(screen.sprite);
    window.display();
}

int main(int, char *[])
{
    sf::RenderWindow window;
    createWindow(window);

    Fighter1 fighter1;
    initializeFighter1(fighter1);

    Fighter2 fighter2;
    initializeFighter2(fighter2);

    Screen screen;
    initializeScreen(screen);

    sf::Clock clock;

    while (window.isOpen())
    {
        if (screen.gameState == GameState::START)
        {
            handleEvents(window, screen, fighter1, fighter2);
            renderStart(window, screen);
        }
        if (screen.gameState == GameState::PLAY)
        {
            handleEvents(window, screen, fighter1, fighter2);
            checkAttack(fighter1, fighter2);
            update(clock, fighter1, fighter2);
            renderPlay(screen, window, fighter1, fighter2);
        }
        if (screen.gameState == GameState::PAUSE)
        {
            handleEvents(window, screen, fighter1, fighter2);
            renderPause(window, screen, fighter1, fighter2);
        }
        if (screen.gameState == GameState::WIN)
        {
            handleEvents(window, screen, fighter1, fighter2);
            renderWin(window, screen);
        }
        if (screen.gameState == GameState::RESTART)
        {
            initializeFighter1(fighter1);
            initializeFighter2(fighter2);
            initializeScreen(screen);
        }
    }

    return 0;
}