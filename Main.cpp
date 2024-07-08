#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "iostream"
#include <fstream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    
    window.setFramerateLimit(60);
    Ball ball = Ball(&window);
    Player playerOne = Player(&window, 1);
    Player playerTwo = Player(&window, 2);

    sf::Text playerOneScore;
    sf::Text playerTwoScore;
    sf::Text finishedText;

    sf::Font font;
    GameState gameState = GameState::PAUSED;
    std::string fontPath = "Fonts/Roboto-Bold.ttf";


    bool isPlayerOneMovingUp = false;
    bool isPlayerOneMovingDown = false;
    bool isPlayerTwoMovingUp = false;
    bool isPlayerTwoMovingDown = false;
     
    if (!fileExists(fontPath)) {
        std::cerr << "El archivo no existe en: " << fontPath << std::endl;
        return -1;
    }
    else {
        std::cout << "El archivo existe en: " << fontPath << std::endl;
    }

    if (!font.loadFromFile(fontPath)) {
        throw("No se puede abrir archivo");
    }
  
    playerOneScore.setFont(font);
    playerTwoScore.setFont(font);
    finishedText.setFont(font);

    playerOneScore.setCharacterSize(50);
    playerTwoScore.setCharacterSize(50);
    finishedText.setCharacterSize(30);

    playerOneScore.setPosition(350 - playerTwoScore.getCharacterSize(), 50);
    playerTwoScore.setPosition(450 + playerTwoScore.getCharacterSize() / 2, 50);
    finishedText.setPosition(225, 250);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    isPlayerOneMovingUp = true;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    isPlayerOneMovingDown = true;
                }

                if (event.key.code == sf::Keyboard::W) {
                    isPlayerTwoMovingUp = true;

                }

                if (event.key.code == sf::Keyboard::S) {
                    isPlayerTwoMovingDown = true;
                }

                if (event.key.code == sf::Keyboard::Space) {
                    switch (gameState)
                    {
                    case PLAYING:
                        gameState = GameState::PAUSED;
                        break;
                    case PAUSED:
                        gameState = GameState::PLAYING;

                        break;
                    default:
                        break;
                    }
                        
                }
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up)
                    isPlayerOneMovingUp = false;
                if (event.key.code == sf::Keyboard::Down)
                    isPlayerOneMovingDown = false;
                if (event.key.code == sf::Keyboard::W)
                    isPlayerTwoMovingUp = false;
                if (event.key.code == sf::Keyboard::S)
                    isPlayerTwoMovingDown = false;
            }
        }

        if (gameState != GameState::FINISHED) {
            if (playerOne.getScore() != 5 && playerTwo.getScore() != 5) {
                if (isPlayerOneMovingUp)
                    playerOne.update(Movement::UP);
                if (isPlayerOneMovingDown)
                    playerOne.update(Movement::DOWN);
                if (isPlayerTwoMovingUp)
                    playerTwo.update(Movement::UP);
                if (isPlayerTwoMovingDown)
                    playerTwo.update(Movement::DOWN);


                if (ball.getPoint() != 0) {
                    gameState = GameState::PAUSED;

                    if (ball.getPoint() == 1) {
                        playerOne.addScore();
                    }
                    else {
                        playerTwo.addScore();
                    }

                    ball.resetPoint();
                }

                window.clear();

                ball.update(playerOne.getPlayerBound(), playerTwo.getPlayerBound(), gameState);
                ball.draw(&window);

                playerOneScore.setString(std::to_string(playerOne.getScore()));
                playerTwoScore.setString(std::to_string(playerTwo.getScore()));

                playerOne.draw(&window);
                playerTwo.draw(&window);

                window.draw(playerOneScore);
                window.draw(playerTwoScore);
            }
            else {
                gameState = GameState::FINISHED;
            }
            
        }
        else {
            window.clear();
            if (playerOne.getScore() == 5)
                finishedText.setString("El ganador es el Jugador 1");
            else
                finishedText.setString("El ganador es el Jugador 2");

            window.draw(finishedText);
        }
        
 
        window.display();
        
    }

    return 0;
}