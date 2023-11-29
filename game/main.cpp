#include "fighters.h"
#include <SFML/Graphics.hpp>

// -- объявления констант --
constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;
constexpr unsigned MAX_FPS = 90;

// Функция создаёт окно приложения.
void createWindow(sf::RenderWindow &window)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(
        sf::VideoMode::getDesktopMode(),
        "Tekken-8", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(MAX_FPS);
}

// Функция обрабатывает все события, скопившиеся в очереди событий SFML.
void handleEvents(sf::RenderWindow &window, Fighter1 &fighter1, Fighter2 &fighter2)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Кнопка закрытия окна
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

// Функция обновляет состояние объектов на сцене.
void update(sf::Clock &clock, Fighter1 &fighter1, Fighter2 &fighter2)
{
    const float elapsedTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    updateFighter1(fighter1, elapsedTime);
    updateFighter2(fighter2, elapsedTime);
}

// Функция рисует объекты на сцене.
void render(sf::RenderWindow &window, const sf::Sprite &backgroundSprite, Fighter1 &fighter1, Fighter2 &fighter2)
{
    window.clear();
    window.draw(backgroundSprite);
    drawFighters(window, fighter1, fighter2);
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

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("img/background.jpg"))
    {
        exit(1);
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::Clock clock;
    while (window.isOpen())
    {
        handleEvents(window, fighter1, fighter2);
        update(clock, fighter1, fighter2);
        render(window, backgroundSprite, fighter1, fighter2);
    }

    return 0;
}