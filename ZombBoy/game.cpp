#include "game.h"


Game::Game() : window(sf::VideoMode(800, 800), "ZombBoy"), gameRender(window) {
    window.setFramerateLimit(60);
}

void Game::run() {

    auto player = std::make_shared<Player>(Vector2D(300, 300));
    //Zombie zomb(Vector2D(500, 500));
    
    gameRender.addEntity(player);
    //gameRender.addEntity(zomb);

    while (gameRender.isOpen())
    {
        // check to close window
        sf::Event event;
        while (gameRender.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameRender.close();
            
        }

        //checking inputs
        inputManager.update();
        if (inputManager.isKeyPressed(sf::Keyboard::W)) {
            // Move player up
            player->move(Vector2D(0.f,-player->move_speed));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::A)) {
            // Move player up
            player->move(Vector2D(-player->move_speed, 0.f));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::S)) {
            // Move player up
            player->move(Vector2D(0.f, player->move_speed));
        }
        if (inputManager.isKeyPressed(sf::Keyboard::D)) {
            // Move player up
            player->move(Vector2D(player->move_speed, 0.f));
        }

        gameRender.render();


        //std::cout << zomb.position.x << " " << zomb.position.y << "\n";
        //std::cout << zomb.getDir().x << " " << zomb.getDir().y << "\n";

    }
}