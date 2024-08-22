#ifndef GAME_HPP
#define GAME_HPP


#include <string>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include "LinkedList.hpp"
class Game 
{
public:
  Game();
  void Draw();
  void Update(float deltaTime);
  void Run();
private:
  void AddElements();
  void RemoveElements();
  void IncreaseSpeed() {speed+=0.5;};
  void DecreaseSpeed() {speed -=0.5;};
  float speed = 0.3f;
  sf::RenderWindow window_;
  sf::ConvexShape* GenerateTriangle(float posx, float posy, float size);
  int elm_count = 0;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Text text;
  sf::Font font;
  std::string title;
  LinkedList<sf::Shape*> elmList_;
  sf::Clock clock;
};
#endif

  
