#include "enemy.h"

Zombie::Zombie(float x, float y)
{
	move_speed = 0.001f;
	position = Vector2D(x, y);
}

Zombie::Zombie(Vector2D _position)
{
    position = _position;
}

Vector2D Zombie::getDir() const
{
    return dir;
}

void Zombie::chase(const Entity& target)
{
	targetPosition = target.position;

    // Calculate the direction vector from zombie to target
    dir = targetPosition - this->position;

    // Normalize the direction vector to get a unit vector
    dir = dir.normalize();

    // Now dir is set to the unit vector pointing towards the target
    // You can use dir to move the zombie in subsequent logic
    this->dir = dir; // Assuming this->dir is a Vector2D member variable of Zombie
}

void Zombie::update()
{
	position += (dir);
}