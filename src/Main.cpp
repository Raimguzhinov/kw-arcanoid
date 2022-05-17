#include <SFML/Graphics.hpp>

#include "Ball.cpp"
#include "MainWindow.cpp"
#include "Platform.cpp"
#include "unistd.h"

void winningGame() {
    sf::Font font;
    font.loadFromFile("font/font.ttf");
}

bool startGame() {
    MainWindow mainWin;
    Platform platform;
    Ball ball;
    Map map;
    sf::RenderWindow window(sf::VideoMode(mainWin.width, mainWin.height),
                            "Arcanoid");
    window.setFramerateLimit(240);

    sf::Font font;
    font.loadFromFile("font/font.ttf");
    sf::Text gameOverWrite1;
    gameOverWrite1.setFont(font);
    gameOverWrite1.setPosition(380, 320);
    gameOverWrite1.setString("Game over!");
    gameOverWrite1.setCharacterSize(100);
    gameOverWrite1.setFillColor(sf::Color::Blue);
    gameOverWrite1.setOutlineThickness(8);
    gameOverWrite1.setOutlineColor(sf::Color::Red);
    gameOverWrite1.setStyle(sf::Text::Bold);
    sf::Text gameOverWrite2;
    gameOverWrite2.setFont(font);
    gameOverWrite2.setPosition(280, 260);
    gameOverWrite2.setString("Mission passed!\n\t   Respect +");
    gameOverWrite2.setCharacterSize(100);
    gameOverWrite2.setFillColor(sf::Color::Blue);
    gameOverWrite2.setOutlineThickness(8);
    gameOverWrite2.setOutlineColor(sf::Color::Red);
    gameOverWrite2.setStyle(sf::Text::Bold);

    map.generate();

    sf::Clock clock;

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            return true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return false;
        }
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (ball.collision(platform, map.getBlocks(), 35) && cntDeaths != 30) {
            platform.moveable();

            ball.updPos();

            window.clear();
            window.draw(mainWin.background);
            window.draw(platform.platformSprite);
            window.draw(ball.ballSprite);
            map.draw(window);
            window.display();
        } else if (cntDeaths == 30) {
            winningGame();
            window.draw(gameOverWrite2);
            window.display();
            sleep(5);
            cntDeaths = 0;
            return false;
        } else {
            window.draw(gameOverWrite1);
            window.display();
            cntDeaths = 0;
        }
    }
    return true;
}

void gameRunning() {  //ф-ция перезагружает игру , если это необходимо
    if (startGame()) {
        gameRunning();
    }  //если startGame() == true, то вызываем занова ф-цию isGameRunning,
       //которая в свою очередь опять вызывает startGame()
}

int main() {
    gameRunning();  //запускаем процесс игры
    return 0;
}
