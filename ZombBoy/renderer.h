#pragma once

#include <unordered_map>
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "entity.h"
#include "TextureManager.h"


class GameRender 
{
public:
	int total;

	GameRender() = delete;
	GameRender(sf::RenderWindow& window);

	bool isOpen();
	bool pollEvent(sf::Event event);

	sf::RenderWindow& getWindow();

	// Adds an Entity to the entity vector to be rendered
	void addEntity(std::shared_ptr<Entity> entity);

	//Closes the Window
	void close();

	// Renders The Frames
	void render();

private:
	sf::RenderWindow& win;
	TextureManager textureManager;

	// Holds all Entities
	std::vector<std::shared_ptr<Entity>> entities;
};