#pragma once
#include <SFML/Graphics.hpp>

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
};

struct Fighter1
{
    sf::Texture textureStay;
    sf::Texture textureStep1;
    sf::Texture textureStep2;
    sf::Texture textureSit;
    sf::Texture textureJump;
    sf::Texture textureFall;
    sf::Texture textureFist;
    sf::Texture textureKick;
    sf::Texture textureSittingKick;
    sf::Sprite sprite;
    DirectionX dirX;
    DirectionY dirY;
    Hit hit;
    float speed;
    float animationTimer;
    float jumpTimer;
    float attackTimer;
    bool isJump;
    bool isAttack;
    bool isAttacked;
    int hp;
    float maxhp;
    int fistDamage;
    int kickDamage;
    int attack;
};

struct Fighter2
{
    sf::Texture textureStay;
    sf::Texture textureStep1;
    sf::Texture textureStep2;
    sf::Texture textureSit;
    sf::Texture textureJump;
    sf::Texture textureFall;
    sf::Texture textureFist;
    sf::Texture textureKick;
    sf::Texture textureSittingKick;
    sf::Sprite sprite;
    DirectionX dirX;
    DirectionY dirY;
    Hit hit;
    float speed;
    float animationTimer;
    float jumpTimer;
    float attackTimer;
    bool isJump;
    bool isAttack;
    bool isAttacked;
    bool isScale;
    int hp;
    float maxhp;
    int fistDamage;
    int kickDamage;
    int attack;
};

void initializeFighter1(Fighter1 &fighter1);
void updateFighter1(Fighter1 &fighter1, float elapsedTime, int WINDOW_WIDTH);

void initializeFighter2(Fighter2 &fighter2);
void updateFighter2(Fighter2 &fighter2, float elapsedTime, int WINDOW_WIDTH);

void checkAttack(Fighter1 &fighter1, Fighter2 &fighter2);
void drawFighters(sf::RenderWindow &window, Fighter1 &fighter1, Fighter2 &fighter2);