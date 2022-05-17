#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Blocks.cpp"
#include "Platform.cpp"

int cntDeaths = 0;

class Ball {
   public:
    float defPosX;
    float defPosY;
    float dirX = 0;
    float dirY = 2;
    float xPos, yPos;
    sf::Texture texture;
    sf::Sprite ballSprite;

    float slowDown = 0.1;

    Ball(float x = 580, float y = 300) {
        defPosX = x;
        defPosY = y;
        texture.loadFromFile("img/ball.png");
        ballSprite.setTexture(texture);
        ballSprite.setPosition(defPosX, defPosY);
        ballSprite.setScale(0.06, 0.06);
        xPos = x;
        yPos = y;
    }

    bool collision(Platform platform, Block* blocks[], int n) {
        srand(time(NULL));
        if (xPos < 0 || xPos > 1160) {
            dirX *= -1;
        }
        if (yPos < 0) {
            dirY *= -1;
        }

        float tempX = platform.getPosX();
        float tempY = platform.getPosY();

        if (yPos <= 0 ||
            xPos <= tempX + 135 && xPos >= tempX - 25 && yPos == tempY + 20) {
            dirX = (((1 + rand() % (5 + 1) - 1) + xPos) /
                    (rand() % (20 + 100) + 20) * slowDown) *
                       -1 +
                   rand() % ((1 + 1) + 1);
            dirY = dirY * -1;
        }

        else if (yPos >= 800) {
            return false;
        }
        for (int i = 0; i < n; i++)
            if (blocks[i] != NULL) {
                sf::Vector2f p = blocks[i]->getPosition();
                if (p.x > xPos + 5 || p.x + 100 < xPos || p.y > yPos + 20 ||
                    p.y + 20 < yPos)
                    continue;
                else {
                    delete blocks[i];
                    cntDeaths += 1;
                    blocks[i] = NULL;
                    if ((p.x + 40) - (xPos + 15) <= 40)
                        dirY *= -1;
                    else
                        dirX *= -1;
                }
            }
        return true;
    }
    void updPos() {
        xPos += dirX;
        yPos += dirY;
        ballSprite.setPosition(xPos, yPos);
    }
};
