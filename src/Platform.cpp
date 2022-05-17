#pragma once

#include <SFML/Graphics.hpp>

class Platform {
   public:
    sf::Texture texture;
    sf::Sprite platformSprite;

    float posX;
    float posY;

    bool checkBorder = false;

    Platform(float defPosX = 520, float defPosY = 600) {
        texture.loadFromFile("img/platform.png");
        platformSprite.setTexture(texture);
        platformSprite.setPosition(defPosX, defPosY);
        platformSprite.setScale(1.2, 1.2);
        posX = defPosX;
        posY = defPosY;
    }

    void movePlatformRight() {
        posX += 4;
        platformSprite.setPosition(posX, posY);
    }
    void movePlatformLeft() {
        posX -= 4;
        platformSprite.setPosition(posX, posY);
    }

    void moveable() {
        if (posX < -25) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                movePlatformRight();
            }
        } else if (posX > 1050) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                movePlatformLeft();
            }
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                movePlatformRight();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                movePlatformLeft();
            }
        }
    }

    float getPosX() { return posX; }
    float getPosY() { return posY; }
};
