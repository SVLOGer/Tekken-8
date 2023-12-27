#include "fighters.h"
#include "screen.h"
#include <iostream>

void initializeScreen(Screen &screen)
{
    if (!screen.texture.loadFromFile("img/background.jpg"))
    {
        exit(1);
    }
    if (!screen.textureSubZeroWin.loadFromFile("img/subzero_win.png"))
    {
        exit(1);
    }
    if (!screen.textureScorpionWin.loadFromFile("img/scorpion_win.png"))
    {
        exit(1);
    }
    if (!screen.texturePause.loadFromFile("img/pause.png"))
    {
        exit(1);
    }
    if (!screen.textureStart.loadFromFile("img/start.png"))
    {
        exit(1);
    }
    screen.spritePause.setTexture(screen.texturePause);
    screen.spriteStart.setTexture(screen.textureStart);
    screen.sprite.setTexture(screen.texture);
    screen.hpBarWidth = 700;
    screen.hpBarHeight = 40;
    screen.gameState = GameState::START;
}

void updateGameState(sf::Event event, Screen &screen, Fighter1 &fighter1, Fighter2 &fighter2)
{
    if (fighter1.hp <= 0)
    {
        screen.gameState = GameState::WIN;
        screen.sprite.setTexture(screen.textureScorpionWin);
    }
    if (fighter2.hp <= 0)
    {
        screen.gameState = GameState::WIN;
        screen.sprite.setTexture(screen.textureSubZeroWin);
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if ((event.key.code == sf::Keyboard::P) && (screen.gameState == GameState::START))
        {
            screen.gameState = GameState::PLAY;
        }
        else
        {
            if ((event.key.code == sf::Keyboard::P) && (screen.gameState == GameState::PLAY))
            {
                screen.gameState = GameState::PAUSE;
            }
            else if ((event.key.code == sf::Keyboard::P) && (screen.gameState == GameState::PAUSE))
            {
                screen.gameState = GameState::PLAY;
                screen.sprite.setTexture(screen.texture);
            }
        }
        if ((event.key.code == sf::Keyboard::R) && (screen.gameState == GameState::WIN))
        {
            screen.gameState = GameState::RESTART;
        }
    }
}

void drawFightersHpBar(Screen &screen, sf::RenderWindow &window, int fighter1Hp, int fighter2Hp, float fighter1MaxHp, float fighter2MaxHp)
{
    sf::RectangleShape shape1;
    shape1.setSize({700, 40});
    shape1.setPosition({50, 50});
    shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape1);
    sf::RectangleShape shape2;
    shape2.setSize({fighter1Hp / fighter1MaxHp * 700, 40});
    shape2.setPosition({50, 50});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);
    sf::RectangleShape shape3;
    shape3.setSize({700, 40});
    shape3.setPosition({1170, 50});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);
    sf::RectangleShape shape4;
    shape4.setSize({fighter2Hp / 100.0f * 700, 40});
    shape4.setPosition({1170 + (700 - fighter2Hp / fighter2MaxHp * 700), 50});
    shape4.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape4);
}