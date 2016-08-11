#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Ball : public sf::Drawable {

  private:
    sf::Vector2f acceleration;
    sf::Vector2f speed;
    sf::RectangleShape shape;

  public:
    Ball();

    bool checkCollision(sf::Vector2f& origin, sf::Vector2f& end);
    void reverse();
    void accelerate();
    void move();
    void draw(sf::RenderTarget& target,
        sf::RenderStates states) override;
    void reset(sf::Vector2f& position);

};
