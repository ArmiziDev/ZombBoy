
#include "renderer.h"


GameRender::GameRender(sf::RenderWindow& window) : win(window), total(0)
{
    win.setFramerateLimit(60);
    if (!MyFont.loadFromFile("font/Arial.ttf"))
    {
        // Error...
    }
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
    std::cout << "Creating Entity: " << entity->getName() << " ID: " << entity->id << "\n";
}

void GameRender::updateGui(int _playerHealth)
{
    playerHealth = _playerHealth;
}

void GameRender::close()
{
    win.close();
}

void GameRender::render()
{
    win.clear();

    sf::Text healthText;
    healthText.setFont(MyFont); // Set the font to our loaded font
    healthText.setString("Health: " + std::to_string(playerHealth)); // Set the initial text
    healthText.setCharacterSize(50); // Set the text size
    healthText.setFillColor(sf::Color::White); // Set the text color
    healthText.setPosition(10.f, 10.f); // Position the text in the top-left corner

    win.draw(healthText);

    for (auto& entity : entities) {
        entity->update();
        auto position = entity->getPosition();

        // draw entity

        sf::Sprite sprite;
        sprite.setPosition(position.x, position.y);
        sf::Texture texture;
        if (!texture.loadFromFile(entity->getTextureFile()))
        {
            
        }
        if (smoothing) texture.setSmooth(true);
        sprite.setTexture(texture);

        sprite.setColor(sf::Color::Color(
        entity->get_color().r, entity->get_color().g, entity->get_color().b
        ));
        sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
        sprite.setRotation(entity->rotation);

        win.draw(sprite);

        // draw hitbox
        if (hitbox_show) {
            sf::RectangleShape rectangle(sf::Vector2f(entity->hitbox.size.x, entity->hitbox.size.y));
            rectangle.setPosition(entity->hitbox.position.x - entity->hitbox.size.x/ 2,
                                    entity->hitbox.position.y - entity->hitbox.size.y / 2);
            rectangle.setFillColor(sf::Color::Transparent); // No fill to see the entity behind it
            rectangle.setOutlineThickness(1.f); // Set the thickness of the outline
            rectangle.setOutlineColor(sf::Color::Red); // Red outline to make it visible

            win.draw(rectangle);
        }
    }

    win.display();
}
