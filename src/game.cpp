#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"

Game::Game() :
  window(sf::VideoMode(800, 600), "O_O"),
  player(sf::Vector2f(20, 10)),
  bot(sf::Vector2f(20, 10)),
  ball(sf::Vector2f(5, 5)) {}

int Game::start() {
  while (window.isOpen()) {
    update();
    render();
  }
  return 0;
}

void Game::update() {
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Up) {
          player.move(0.0f, -5.0f);
        } else if (event.key.code == sf::Keyboard::Up) {
          player.move(0.0f, 5.0f);
        }
        break;
      default:
        break;
    }
  }
}

void Game::render() {
  window.clear();
  window.draw(player);
  window.draw(bot);
  window.draw(ball);
  window.display();
}

void Game::exit() {
}
