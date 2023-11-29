#include "fighters.h"
#include <iostream>

const sf::IntRect textureRectSit(0, 0, 206, 216);
const sf::IntRect textureRectStay(0, 0, 206, 270);
const sf::IntRect textureRectJump(0, 0, 206, 182);

static void jumpFighter1(Fighter1 &fighter1, float step)
{
    fighter1.jumpTimer += step;
    if (fighter1.jumpTimer > 75)
    {
        fighter1.sprite.setTextureRect(textureRectStay);
        fighter1.sprite.setTexture(fighter1.textureFall);
        fighter1.sprite.setPosition(fighter1.sprite.getPosition().x, 735);
    }
    if (fighter1.jumpTimer > 100)
    {
        fighter1.jumpTimer = 0;
        fighter1.isJump = false;
    }
}

static void jumpFighter2(Fighter2 &fighter2, float step)
{
    fighter2.jumpTimer += step;
    if (fighter2.jumpTimer > 75)
    {
        fighter2.sprite.setTextureRect(textureRectStay);
        fighter2.sprite.setTexture(fighter2.textureFall);
        fighter2.sprite.setPosition(fighter2.sprite.getPosition().x, 735);
    }
    if (fighter2.jumpTimer > 100)
    {
        fighter2.jumpTimer = 0;
        fighter2.isJump = false;
    }
}

static void changeScaleFighters(Fighter1 &fighter1, Fighter2 &fighter2)
{
    sf::Vector2f fighter1Position = fighter1.sprite.getPosition();
    sf::Vector2f fighter2Position = fighter2.sprite.getPosition();
    if (fighter1Position.x < fighter2Position.x)
    {
        fighter1.sprite.setScale(1, 1);
        fighter2.sprite.setScale(1, 1);
    }
    else
    {
        fighter1.sprite.setScale(-1, 1);
        fighter2.sprite.setScale(-1, 1);
    }
}

static void updateFighter1Sprite(Fighter1 &fighter1)
{
    if (fighter1.animationTimer >= 0.2)
    {
        fighter1.animationTimer = 0;
        fighter1.sprite.setTexture(fighter1.textureStep2);
    }
    else
    {
        if (fighter1.animationTimer >= 0.1)
        {
            fighter1.sprite.setTexture(fighter1.textureStep1);
        }
    }
}

static void updateFighter2Sprite(Fighter2 &fighter2)
{
    if (fighter2.animationTimer >= 0.2)
    {
        fighter2.animationTimer = 0;
        fighter2.sprite.setTexture(fighter2.textureStep2);
    }
    else
    {
        if (fighter2.animationTimer >= 0.1)
        {
            fighter2.sprite.setTexture(fighter2.textureStep1);
        }
    }
}

static void updateFighter1Hit(Fighter1 &fighter1)
{

    fighter1.hit = Hit::NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
    }
}

static void updateFighter2Hit(Fighter2 &fighter2)
{

    fighter2.hit = Hit::NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
    }
}

static void updateFighter1Direction(Fighter1 &fighter1)
{

    fighter1.dirX = DirectionX::NONE;
    if (!fighter1.isJump)
    {
        fighter1.dirY = DirectionY::NONE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && fighter1.dirY == DirectionY::NONE && !fighter1.isJump)
    {
        fighter1.dirY = DirectionY::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && fighter1.dirY == DirectionY::NONE)
    {
        fighter1.dirY = DirectionY::DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && fighter1.dirY == DirectionY::NONE)
    {
        fighter1.dirX = DirectionX::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && fighter1.dirY == DirectionY::NONE)
    {
        fighter1.dirX = DirectionX::RIGHT;
    }
}

static void updateFighter2Direction(Fighter2 &fighter2)
{
    fighter2.dirX = DirectionX::NONE;
    if (!fighter2.isJump)
    {
        fighter2.dirY = DirectionY::NONE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && fighter2.dirY == DirectionY::NONE)
    {
        if (!fighter2.isJump)
        {
            fighter2.dirY = DirectionY::UP;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && fighter2.dirY == DirectionY::NONE)
    {
        fighter2.dirY = DirectionY::DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && fighter2.dirY == DirectionY::NONE)
    {
        fighter2.dirX = DirectionX::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && fighter2.dirY == DirectionY::NONE)
    {
        fighter2.dirX = DirectionX::RIGHT;
    }
}

void initializeFighter1(Fighter1 &fighter1)
{
    fighter1.dirX = DirectionX::NONE;
    fighter1.dirY = DirectionY::NONE;
    if (!fighter1.textureStay.loadFromFile("img/fighter1_stay.png"))
    {
        exit(1);
    }
    if (!fighter1.textureStep1.loadFromFile("img/fighter1_step1.png"))
    {
        exit(1);
    }
    if (!fighter1.textureStep2.loadFromFile("img/fighter1_step2.png"))
    {
        exit(1);
    }
    if (!fighter1.textureSit.loadFromFile("img/fighter1_sit.png"))
    {
        exit(1);
    }
    if (!fighter1.textureJump.loadFromFile("img/fighter1_jump.png"))
    {
        exit(1);
    }
    if (!fighter1.textureFall.loadFromFile("img/fighter1_fall.png"))
    {
        exit(1);
    }
    fighter1.sprite.setTexture(fighter1.textureStay);
    fighter1.sprite.setOrigin(103, 135);
    fighter1.speed = 200.f;
    fighter1.animationTimer = 0;
    fighter1.sprite.setPosition(300, 735);
    fighter1.jumpTimer = 0;
    fighter1.isJump = false;
    fighter1.hit = Hit::NONE;
    fighter1.hp = 100;
}

void initializeFighter2(Fighter2 &fighter2)
{
    fighter2.dirX = DirectionX::NONE;
    fighter2.dirY = DirectionY::NONE;
    if (!fighter2.textureStay.loadFromFile("img/fighter2_stay.png"))
    {
        exit(1);
    }
    if (!fighter2.textureStep1.loadFromFile("img/fighter2_step1.png"))
    {
        exit(1);
    }
    if (!fighter2.textureStep2.loadFromFile("img/fighter2_step2.png"))
    {
        exit(1);
    }
    if (!fighter2.textureSit.loadFromFile("img/fighter2_sit.png"))
    {
        exit(1);
    }
    if (!fighter2.textureJump.loadFromFile("img/fighter2_jump.png"))
    {
        exit(1);
    }
    if (!fighter2.textureFall.loadFromFile("img/fighter2_fall.png"))
    {
        exit(1);
    }
    fighter2.sprite.setTexture(fighter2.textureStay);
    fighter2.sprite.setOrigin(103, 135);
    fighter2.speed = 200.f;
    fighter2.animationTimer = 0;
    fighter2.sprite.setPosition(1600, 735);
    fighter2.jumpTimer = 0;
    fighter2.isJump = false;
    fighter2.hit = Hit::NONE;
    fighter2.hp = 100;
}

void updateFighter1(Fighter1 &fighter1, float elapsedTime, int WINDOW_WIDTH)
{
    sf::Vector2f fighter1Pos = fighter1.sprite.getPosition();
    float step = fighter1.speed * elapsedTime;

    bool isFighterStayY = false;
    bool isFighterStayX = false;

    if (fighter1.hit == Hit::NONE)
    {
        updateFighter1Direction(fighter1);
    }
    else
    {
        fighter1.dirX = DirectionX::NONE;
        fighter1.dirY = DirectionY::NONE;
    }
    updateFighter1Sprite(fighter1);

    sf::Vector2f movement(0.f, 0.f);
    switch (fighter1.dirY)
    {
    case DirectionY::UP:
        fighter1.sprite.setPosition(fighter1.sprite.getPosition().x, 700);
        fighter1.sprite.setTexture(fighter1.textureJump);
        fighter1.sprite.setTextureRect(textureRectJump);
        fighter1.isJump = true;
        jumpFighter1(fighter1, step);
        break;
    case DirectionY::DOWN:
        fighter1.sprite.setPosition(fighter1.sprite.getPosition().x, 833);
        fighter1.sprite.setTexture(fighter1.textureSit);
        fighter1.sprite.setTextureRect(textureRectSit);
        break;
    case DirectionY::NONE:
        fighter1.sprite.setTextureRect(textureRectStay);
        fighter1.sprite.setPosition(fighter1.sprite.getPosition().x, 735);
        isFighterStayY = true;
        break;
    }
    switch (fighter1.dirX)
    {
    case DirectionX::LEFT:
        if (fighter1Pos.x - step < 135)
        {
            movement.x = 0;
        }
        else
        {
            movement.x -= step;
        }
        fighter1.animationTimer += elapsedTime;
        break;
    case DirectionX::RIGHT:
        if (fighter1Pos.x + step > WINDOW_WIDTH - 135)
        {
            movement.x = 0;
        }
        else
        {
            movement.x += step;
        }
        fighter1.animationTimer += elapsedTime;
        break;
    case DirectionX::NONE:
        isFighterStayX = true;
        break;
    }
    if (isFighterStayX && isFighterStayY)
    {
        fighter1.sprite.setTexture(fighter1.textureStay);
    }
    fighter1.sprite.move(movement);
}

void updateFighter2(Fighter2 &fighter2, float elapsedTime, int WINDOW_WIDTH)
{
    sf::Vector2f fighter2Pos = fighter2.sprite.getPosition();
    const float step = fighter2.speed * elapsedTime;

    bool isFighterStayY = false;
    bool isFighterStayX = false;

    if (fighter2.hit == Hit::NONE)
    {
        updateFighter2Direction(fighter2);
    }
    else
    {
        fighter2.dirX = DirectionX::NONE;
        fighter2.dirY = DirectionY::NONE;
    }
    updateFighter2Sprite(fighter2);

    sf::Vector2f movement(0.f, 0.f);
    switch (fighter2.dirY)
    {
    case DirectionY::UP:
        fighter2.sprite.setPosition(fighter2.sprite.getPosition().x, 700);
        fighter2.sprite.setTexture(fighter2.textureJump);
        fighter2.sprite.setTextureRect(textureRectJump);
        fighter2.isJump = true;
        jumpFighter2(fighter2, step);
        break;
    case DirectionY::DOWN:
        fighter2.sprite.setPosition(fighter2.sprite.getPosition().x, 833);
        fighter2.sprite.setTexture(fighter2.textureSit);
        fighter2.sprite.setTextureRect(textureRectSit);
        break;
    case DirectionY::NONE:
        fighter2.sprite.setTextureRect(textureRectStay);
        fighter2.sprite.setPosition(fighter2.sprite.getPosition().x, 725);
        isFighterStayY = true;
        break;
    }
    switch (fighter2.dirX)
    {
    case DirectionX::LEFT:
        if (fighter2Pos.x - step < 135)
        {
            movement.x = 0;
        }
        else
        {
            movement.x -= step;
        }
        fighter2.animationTimer += elapsedTime;
        break;
    case DirectionX::RIGHT:
        if (fighter2Pos.x + step > WINDOW_WIDTH - 135)
        {
            movement.x = 0;
        }
        else
        {
            movement.x += step;
        }
        fighter2.animationTimer += elapsedTime;
        break;
    case DirectionX::NONE:
        isFighterStayX = true;
        break;
    }
    if (isFighterStayX && isFighterStayY)
    {
        fighter2.sprite.setTexture(fighter2.textureStay);
    }
    fighter2.sprite.move(movement);
}

void drawFighters(sf::RenderWindow &window, Fighter1 &fighter1, Fighter2 &fighter2)
{
    changeScaleFighters(fighter1, fighter2);
    window.draw(fighter1.sprite);
    window.draw(fighter2.sprite);
}