#pragma once
#include <SFML/Graphics.hpp>

// Направление движения (не движется, вверх, вниз, влево, вправо)
enum struct DirectionX
{
    NONE,
    LEFT,
    RIGHT
};

enum struct DirectionY
{
    NONE,
    UP,
    DOWN
};

enum struct Hit
{
    NONE,
    HAND,
    LEG
}

struct Fighter1
{
    sf::Texture textureStay;
    sf::Texture textureStep1;
    sf::Texture textureStep2;
    sf::Texture textureSit;
    sf::Texture textureJump;
    sf::Texture textureFall;
    sf::Sprite sprite;
    DirectionX dirX;
    DirectionY dirY;
    Hit hit;
    float speed;
    float animationTimer;
    float jumpTimer;
    bool isJump;
    int hp;
};

struct Fighter2
{
    sf::Texture textureStay;
    sf::Texture textureStep1;
    sf::Texture textureStep2;
    sf::Texture textureSit;
    sf::Texture textureJump;
    sf::Texture textureFall;
    sf::Sprite sprite;
    DirectionX dirX;
    DirectionY dirY;
    Hit hit;
    float speed;
    float animationTimer;
    float jumpTimer;
    bool isJump;
    int hp;
};

void initializeFighter1(Fighter1 &fighter1);
void updateFighter1(Fighter1 &fighter1, float elapsedTime);

void initializeFighter2(Fighter2 &fighter2);
void updateFighter2(Fighter2 &fighter2, float elapsedTime);

void drawFighters(sf::RenderWindow &window, Fighter1 &fighter1, Fighter2 &fighter2);