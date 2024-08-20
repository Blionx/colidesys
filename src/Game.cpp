#include "Game.hpp"
#include <iostream>

Game::Game(){
  window_.create(sf::VideoMode(1024, 768), "Tester");
  // Load a sprite to display
  if (!texture.loadFromFile("cute_image.jpg"))
    std::cout <<"ERROR SPRITE! \n";
  sprite.setTexture(texture);
 
  // Create a graphical text to display
  if (!font.loadFromFile("tuffy.ttf"))
    std::cout <<"ERROR FONT! \n";
  
  std::string str = "Numero de elementos = " + std::to_string(elm_count);

  text = sf::Text(str.c_str(), font, 30);

   for( int i = 0 ; i < 1000; i++)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr1(0, 1024);
    std::uniform_int_distribution<> distr2(0, 768);
    elements_.push_back(GenerateTriangle(distr1(gen), distr2(gen), 5.f));
  }
}

void Game::Draw(){
  // Clear screen
  window_.clear();

  // Draw the sprite

  window_.draw(sprite);

  // Draw the string
  window_.draw(text);

  for (sf::Shape* elm : elements_) {
    window_.draw(*elm);
  }


  // Update the window
  window_.display();
}

void Game::Update() {
   // Clear screen
  window_.clear();

  // Draw the sprite

  window_.draw(sprite);

  // Draw the string
  window_.draw(text);
  for (sf::Shape* elm : elements_) {
    sf::Vector2f pos = elm->getPosition();
    if(pos.x > 1024)
      elm->setPosition(0,pos.y);
    if(pos.x < 0)
       elm->setPosition(1024,pos.y);
    if(pos.y>768)
      elm->setPosition(pos.x,0);
    if(pos.y<0)
      elm->setPosition(pos.x,768);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr1(-2.5f, 5.5f);
    std::uniform_real_distribution<> distr2(-2.5f, 5.5f);
    float x = distr1(gen);
    float y = distr2(gen);

    elm->move(x, y);
    window_.draw(*elm);
  }

  // Update the window
  window_.display();
}

sf::ConvexShape* Game::GenerateTriangle(float posx, float posy, float size)
{
    //Dibujar Triangulo:
    float height = posy + size;
    sf::ConvexShape* triangle = new sf::ConvexShape();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0, 0)); // Primer punto
    triangle->setPoint(1, sf::Vector2f(- size, size)); // Segundo punto
    triangle->setPoint(2, sf::Vector2f(size, size)); // Tercer punto
    triangle->setFillColor(sf::Color::Red);
    triangle->setPosition(posx, posy);

    // sf::VertexArray* triangle = new sf::VertexArray(sf::Triangles, 3);
    // float height = posy + size;
    // // Establece las posiciones de los vértices
    // (*triangle)[0].position = sf::Vector2f(posx, posy);  // Vértice superior
    // (*triangle)[1].position = sf::Vector2f(posx - size, height);  // Vértice inferior izquierdo
    // (*triangle)[2].position = sf::Vector2f(posx + size, height);  // Vértice inferior derecho

    // // Opcional: Establece el color de los vértices
    // (*triangle)[0].color = sf::Color::Red;
    // (*triangle)[1].color = sf::Color::Red;
    // (*triangle)[2].color = sf::Color::Red;

    return triangle;
}

void Game::Run()
{
   // Start the game loop
    while (window_.isOpen())
    {
        // Process events
        sf::Event event;
        while (window_.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        this->Update();
    }
}