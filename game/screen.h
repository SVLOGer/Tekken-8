#pragma once
#include <SFML/Graphics.hpp>
#include "fighters.h"

enum struct GameState
{
    START,
    PLAY,
    PAUSE,
    WIN,
    RESTART
};

struct Screen
{
    sf::Texture texture;
    sf::Texture textureSubZeroWin;
    sf::Texture textureScorpionWin;
    sf::Texture texturePause;
    sf::Texture textureStart;
    sf::Sprite sprite;
    sf::Sprite spritePause;
    sf::Sprite spriteStart;
    int hpBarWidth;
    int hpBarHeight;
    GameState gameState;
};

void initializeScreen(Screen &screen);
void updateGameState(sf::Event event, Screen &screen, Fighter1 &fighter1, Fighter2 &fighter2);
void drawFightersHpBar(Screen &screen, sf::RenderWindow &window, int fighter1Hp, int fighter2Hp, float fighter1MaxHp, float fighter2MaxHp);