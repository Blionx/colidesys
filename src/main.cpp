#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <random>

sf::VertexArray GenerateTriangle(float posx, float posy, float size)
{
    //Dibujar Triangulo:
    sf::VertexArray triangle(sf::Triangles, 3);
    float height = posy + size;
    // Establece las posiciones de los vértices
    triangle[0].position = sf::Vector2f(posx, posy);  // Vértice superior
    triangle[1].position = sf::Vector2f(posx - size, height);  // Vértice inferior izquierdo
    triangle[2].position = sf::Vector2f(posx + size, height);  // Vértice inferior derecho

    // Opcional: Establece el color de los vértices
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Red;
    triangle[2].color = sf::Color::Red;

    return triangle;
}
 
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
     std::uniform_int_distribution<> distr1(0, 1024);
      std::uniform_int_distribution<> distr2(0, 768);
    int elm_count = 0;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Tester");
 
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
 
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("tuffy.ttf"))
        return EXIT_FAILURE;
    std::string str = "Numero de elementos = " + std::to_string(elm_count);

    sf::Text text(str.c_str(), font, 30);
 
    // // Load a music to play
    // sf::Music music;
    // if (!music.openFromFile("nice_music.ogg"))
    //     return EXIT_FAILURE;
 
    // // Play the music
    // music.play();


    
 
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        // Draw the sprite
        window.draw(sprite);
 
        // Draw the string
        window.draw(text);
        for( int i = 0 ; i < 1000; i++)
        {
            // Dibuja el triángulo
        window.draw(GenerateTriangle(distr1(gen), distr2(gen), 5.f));
        }
         
 
        // Update the window
        window.display();
    }
 
    return EXIT_SUCCESS;
}