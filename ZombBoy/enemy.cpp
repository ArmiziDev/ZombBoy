#include "enemy.h"

void Zombie::initialize()
{
    move_speed = 0.001f;
    damage = 5;
    setTexture("zombie.png");
}

Zombie::Zombie(float x, float y)
{
	position = Vector2D(x, y);
    initialize();
}

Zombie::Zombie(Vector2D _position)
{
    position = _position;
    initialize();
}

Vector2D Zombie::getDir() const
{
    return dir;
}

void Zombie::chase(Entity* _target)
{
    target = _target;
}

void Zombie::update()
{
    if (target) {
        Vector2D targetPosition = target->position;

        // Calculate the direction vector from zombie to target
        dir = targetPosition - this->position;

        // Normalize the direction vector to get a unit vector
        dir = dir.normalize();

        // Now dir is set to the unit vector pointing towards the target
        // You can use dir to move the zombie in subsequent logic
        this->dir = dir; // Assuming this->dir is a Vector2D member variable of Zombie
        position += (dir);

        if (checkCollision(target))
        {
            target->damage(damage);
        }
    }
}