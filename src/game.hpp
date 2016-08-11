#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "ball.hpp"

class Game {
  private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::RectangleShape bot;
    Ball ball;

    void handleInput();
    void create();
    void update();
    void render();

  public:
    Game();
    int start();
    void exit();

};
