// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2D.h"
#include "hitbox.h"
#include "idGenerator.h"
#include <string>

class Entity {
public:
    int id = IDGenerator::getInstance().getNextID();

    Entity(float x = 0.0f, float y = 0.0f);
    virtual ~Entity(); // Make the destructor virtual

    void move(const Vector2D& direction);
    void setAncor(bool);

    void damage(int value);

    void setTexture(std::string pathToTexture);
    std::string getTextureFile() const;
    
    void update();
    int setId(int id);

    bool checkCollision(Entity* other);

    Vector2D getPosition() const;

    Vector2D position;
    Vector2D velocity;
    Vector2D dir;

    float friction = 0.92f;

    Hitbox hitbox;

private:
    float health;
    bool ancor;
    std::string texture;

};

#endif // ENTITY_H
