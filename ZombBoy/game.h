#pragma once
#include "InputManager.h"
#include "renderer.h"
#include "player.h"
#include "enemy.h"


class Game {
public:

	Game();

	void run();

	sf::RenderWindow window;
	InputManager inputManager;
	GameRender gameRender;
};