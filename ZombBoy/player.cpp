#include "player.h"

void Player::initialize()
{
	setTexture("player.png");
}

Player::Player() : x(0), y(0)
{
	position = Vector2D(0.f, 0.f);
	initialize();
}

Player::Player(int _x, int _y) : x(_x), y(_y)
{
	position = Vector2D(_x, _y);
	initialize();
}

Player::Player(Vector2D cordinates)
{
	position = cordinates;
	x = position.x;
	y = position.y;
	initialize();
}

Player::~Player()
{
	
}

void Player::update()
{
	position += velocity;
	velocity = velocity * friction; //simulate friction
}

void Player::move(Vector2D mov)
{
	velocity += mov;
}
