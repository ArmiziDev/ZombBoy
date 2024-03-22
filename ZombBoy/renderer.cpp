
#include "renderer.h"

GameRender::GameRender(sf::RenderWindow& window) : win(window), total(0)
{
    win.setFramerateLimit(60);
}

bool GameRender::isOpen()
{
    return win.isOpen();
}

bool GameRender::pollEvent(sf::Event event) {
    return win.pollEvent(event);
}

sf::RenderWindow& GameRender::getWindow()
{
    return win;
}

void GameRender::addEntity(std::shared_ptr<Entity> entity)
{
    entities.push_back(entity);
}

void GameRender::close()
{
    win.close();
}

void GameRender::render()
{
    win.clear();

    for (auto& entity : entities) {
        entity->update();
        sf::Sprite sprite;
        //sprite.setTexture(textureManager.loadTexture(entity.getTextureFile()));
        sf::Texture texture;
        if (!texture.loadFromFile(entity->getTextureFile()))
        {
            
        }
        sprite.setTexture(texture);
        auto position = entity->getPosition();
        sprite.setPosition(position.x, position.y);
        win.draw(sprite);
    }

    win.display();
}
