#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game {
  private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::RectangleShape bot;
    sf::RectangleShape ball;

    void create();
    void update();
    void render();

  public:
    Game();
    int start();
    void exit();

};
