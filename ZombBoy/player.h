#pragma once
#include "entity.h"

enum stats
{
	status,
	health,
	level,
	xp,
	gold
};


class Player : public Entity
{
public:
	Player();
	Player(int x, int y);
	Player(Vector2D cordinates);
	~Player();

	void update();

	void move(Vector2D mov);

	void spawn(int x, int y);
	void spawn(Vector2D cordinates);

	void add_xp(int);

	float x, y;

	//Vector2D position;
	//Vector2D velocity;

	float move_speed = 0.5f;
};