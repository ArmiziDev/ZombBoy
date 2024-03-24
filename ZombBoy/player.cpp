#include "player.h"

void Player::initialize()
{
	setTexture("png/ship_H.png");
	setName("player");
    set_color(0,255,0);
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

Player::Player(Vector2D cordinates) : x(cordinates.x), y(cordinates.y)
{
	position = cordinates;
	initialize();
}

Player::~Player()
{
	
}

void Player::update()
{
    velocity += acceleration;
    float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

    if (speed > maxSpeed) {
        velocity.x = (velocity.x / speed) * maxSpeed;
        velocity.y = (velocity.y / speed) * maxSpeed;
    }

    // Apply drag if not accelerating (simulate deceleration)
    if (acceleration.x == 0 && acceleration.y == 0) {
        velocity.x *= drag;
        velocity.y *= drag;
        }
    // Update position
    position += velocity;

    // Reset acceleration
    acceleration = Vector2D(0.0f, 0.0f);

    rotation = (std::atan2(velocity.y, velocity.x) * 180.0f / 3.1415) + 90.0f;

    //std::cout << "Velocity of Entity: (" << velocity.x << ", " << velocity.y << ")\n";
    /*
    if (damaged)
    {
        set_color(255, 0, 0);
    } 
    */

    Entity::update();
}

void Player::move(Vector2D mov)
{

	velocity += mov;
}