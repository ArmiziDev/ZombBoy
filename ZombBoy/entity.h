// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2D.h"
#include "hitbox.h"
#include "idGenerator.h"
#include <string>
#include <memory>
#include <iostream>
#include <cmath>

struct rgb 
{
    int r = 0;
    int g = 0;
    int b = 0;
};


class Entity {
public:
    int id = IDGenerator::getInstance().getNextID();

    Entity(float x = 0.0f, float y = 0.0f);
    virtual ~Entity(); // Make the destructor virtual

    virtual void update();

    void move(const Vector2D& direction);
    void setAncor(bool);

    int getHealth();
    void damage(int value);
    
    std::string getName();
    void setName(std::string name);

    void set_color(int r, int g, int b);
    rgb get_color() const;

    void setTexture(std::string pathToTexture);
    std::string getTextureFile() const;
    
    int setId(int id);

    bool checkCollision(std::shared_ptr<Entity> other);

    Vector2D getPosition() const;

    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D dir;

    float friction = 0.96f;
    float rotation = 0.f;

    Hitbox hitbox;

    bool damaged;


private:
    int health;
    bool ancor;

    std::string entity_name;
    std::string texture;
    rgb color;

    


};

#endif // ENTITY_H
