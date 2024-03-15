// Entity.cpp
#include "Entity.h"

Entity::Entity(float x, float y) : position(x, y), health(100), ancor(false) //, id(globalEntityId++)
{
    hitbox = Hitbox(position, Vector2D(50,50));


}

Entity::~Entity() {
    // Cleanup resources if any
}

void Entity::move(const Vector2D& direction) {
    this->position += direction;
}

void Entity::update()
{
    if (!ancor)
    {
        position += velocity;
        velocity = velocity * friction; //simulate friction
    }
    
}

int Entity::setId(int _id)
{
    this->id = _id;
    return this->id;
}



void Entity::setAncor(bool a)
{
    ancor = a;
}

Vector2D Entity::getPosition()
{
    return this->position;
}