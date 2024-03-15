#include "game.h"
#include "player.h"
#include "enemy.h"

void Game::run() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "ZombBoy");
    window.setFramerateLimit(60);


    Player player(Vector2D(300,300));
    Zombie zomb(Vector2D(500, 500));

    sf::CircleShape shape(30.f);
    sf::CircleShape enem(30.f);


    shape.setFillColor(sf::Color::Green);
    enem.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        // check to close window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        //checking inputs
        inputManager.update();
        if (inputManager.isKeyPressed(sf::Keyboard::W)) {
            // Move player up
            player.move(Vector2D(0.f,-player.move_speed));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::A)) {
            // Move player up
            player.move(Vector2D(-player.move_speed, 0.f));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::S)) {
            // Move player up
            player.move(Vector2D(0.f, player.move_speed));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::D)) {
            // Move player up
            player.move(Vector2D(player.move_speed, 0.f));
        }



        player.update();
        zomb.chase(player);
        zomb.update();

        shape.setPosition(player.position.x, player.position.y);
        enem.setPosition(zomb.position.x, zomb.position.y);

        //std::cout << zomb.position.x << " " << zomb.position.y << "\n";
        //std::cout << zomb.getDir().x << " " << zomb.getDir().y << "\n";

        //drawing scene
        window.clear();
        window.draw(shape);
        window.draw(enem);
        window.display();
    }
}