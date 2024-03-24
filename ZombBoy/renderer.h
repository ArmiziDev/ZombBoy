#pragma once

#include <unordered_map>
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
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

	// Updates the player stats gui to be rendered onto the screen
	void updateGui(int playerHealth);

	//Closes the Window
	void close();

	// Renders The Frames
	void render();

	// Debug
	bool hitbox_show = false;
	bool debug_show = false;
	bool smoothing = false;

private:
	sf::RenderWindow& win;
	sf::Font MyFont;
	TextureManager textureManager;

	int playerHealth = 100;

	// Holds all Entities
	std::vector<std::shared_ptr<Entity>> entities;
};