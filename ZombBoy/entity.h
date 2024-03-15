// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2D.h"
#include "hitbox.h"

//unsigned int globalEntityId = 1;

class Entity {
public:
    int id;

    Entity(float x = 0.0f, float y = 0.0f);
    virtual ~Entity(); // Make the destructor virtual

    void move(const Vector2D& direction);
    void setAncor(bool);
    
    void update();
    int setId(int id);

    Vector2D getPosition();

    Vector2D position;
    Vector2D velocity;
    Vector2D dir;

    float friction = 0.92f;

    Hitbox hitbox;

protected:
    float health;
    bool ancor;
};

#endif // ENTITY_H
