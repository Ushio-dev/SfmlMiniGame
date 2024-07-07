#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    
    window.setFramerateLimit(60);
    Ball ball = Ball(&window);
    Player player = Player(&window);
    sf::Text texto = sf::Text();
    sf::Font font;
     /*
    if (!font.loadFromFile("fonts/bahnschrift.ttf")) {
        // error 
        //throw("No se puede abrir archivo");
        return 1;
    }
    */

    texto.setFont(font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    player.update(Movement::UP);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    player.update(Movement::DOWN);
                }
            }
        }

        window.clear();
       // window.draw(shape);
        ball.update(player.getPlayerBound());
        ball.draw(&window);
        player.draw(&window);
        texto.setString("Hola Mundo");
        window.display();
    }

    return 0;
}