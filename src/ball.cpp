#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "ball.hpp"

Ball::Ball() :
  acceleration(sf::Vector2f(0.3f, 0.1f)),
  speed(sf::Vector2f(0.1f, 0.1f)),
  shape(sf::Vector2f(5, 5)) {
}

sf::RectangleShape& Ball::getShape() {
  return shape;
}

bool Ball::checkCollision(sf::Vector2f& origin, sf::Vector2f& end) {
  sf::Vector2f ballOrigin = shape.getPosition();
  sf::Vector2f ballSize = shape.getSize();

  return (origin.x < ballOrigin.x + ballSize.x
      && end.x > ballOrigin.x
      && origin.y < ballOrigin.y + ballSize.x
      && end.y > ballOrigin.y);
}


void Ball::reverse() {
  speed.x = -speed.x;
  speed.y = -speed.y;
}

void Ball::accelerate() {
  speed.x = (speed.x < 0.0f)
      ? speed.x - acceleration.x
      : speed.x + acceleration.y;
  speed.y = (speed.y < 0.0f)
      ? speed.y - acceleration.y
      : speed.y + acceleration.y;
}

void Ball::move() {
  shape.setPosition(shape.getPosition() + speed);
}

void Ball::draw(sf::RenderTarget& target,
    sf::RenderStates states) {
  shape.draw(target, states);
}

void Ball::reset(sf::Vector2f& position) {
  shape.setPosition(position);
}
