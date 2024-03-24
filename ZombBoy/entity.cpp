// Entity.cpp
#include "Entity.h"


Entity::Entity(float x, float y) : position(x, y), health(100), ancor(false)
{
    hitbox = Hitbox(position, Vector2D(32,32));
    
}

Entity::~Entity() {
    // Cleanup resources if any
}

void Entity::move(const Vector2D& direction) {
    this->position += direction;
}

void Entity::update()
{
    hitbox.updatePosition(position); 
    damaged = false;
}

int Entity::setId(int _id)
{
    this->id = _id;
    return this->id;
}

bool Entity::checkCollision(std::shared_ptr<Entity> other)
{
    return hitbox.intersects(other->hitbox);
}

void Entity::set_color(int r,int g,int b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

rgb Entity::get_color() const
{
    return color;
}


void Entity::setAncor(bool a)
{
    ancor = a;
}

int Entity::getHealth()
{
    return health;
}

void Entity::damage(int value)
{
    health -= value;
    damaged = true;
}

std::string Entity::getName()
{
    return entity_name;
}

void Entity::setName(std::string name)
{
    entity_name = name;
}

void Entity::setTexture(std::string pathToTexture)
{
    texture = pathToTexture;
}

std::string Entity::getTextureFile() const
{
    return this->texture;
}

Vector2D Entity::getPosition() const
{
    return this->position;
}