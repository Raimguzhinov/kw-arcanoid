#include <SFML/Graphics.hpp>
#include <ctime>

class Block {
   public:
    sf::Vector2f pos;
    sf::RectangleShape rect;
    sf::Color color;

    Block(float x, float y, sf::Color c) {
        pos.x = x;
        pos.y = y;
        color = c;
    }
    sf::Vector2f getPosition() { return pos; }
    void draw(sf::RenderWindow& w) {
        rect.setSize(sf::Vector2f(100, 40));
        rect.setFillColor(color);
        rect.setPosition(pos);
        w.draw(rect);
    }
};

class Map {
   public:
    Block* blocks[7 * 5];

    Block** getBlocks() { return &(blocks[0]); }
    void generate() {
        sf::Color color = sf::Color::Green;

        for (int i = 0; i < 35; i++) {
            blocks[i] = new Block(i % 7 * 220, (i / 7) * 60, color);
        }
    }

    void draw(sf::RenderWindow& win) {
        for (int i = 0; i < 35; i++)
            if (blocks[i] != NULL) blocks[i]->draw(win);
    }
};
