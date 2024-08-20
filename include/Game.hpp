#ifndef GAME_HPP
#define GAME_HPP


#include <string>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
class Game 
{
public:
  Game();
  void Draw();
  void Update();
  void Run();
private:
  sf::RenderWindow window_;
  sf::ConvexShape* GenerateTriangle(float posx, float posy, float size);
  int elm_count = 0;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Text text;
  sf::Font font;
  std::vector<sf::Shape*> elements_;
};
#endif

  
