#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Paddle {

  private:
    sf::Vector2f speed;
    sf::RectangleShape shape;

  public:
    Paddle();
    sf::RectangleShape& getShape();

    bool checkCollision(sf::Vector2f& origin, sf::Vector2f& end);

    sf::Vector2f& getSize();
    sf::Vector2f& getPosition();

    void moveUp();
    void moveDown();

};

