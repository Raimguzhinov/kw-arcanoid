#include <SFML/Graphics.hpp>

class MainWindow {
   public:
    const int width = 1200;
    const int height = 800;
    sf::Texture texture;
    sf::Sprite background;
    MainWindow() {
        texture.loadFromFile("img/back1.jfif");
        background.setTexture(texture);
        background.setScale(3, 2.5);
    }
};

