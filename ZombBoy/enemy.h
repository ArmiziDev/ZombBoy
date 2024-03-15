#pragma once

#include "entity.h"

class Zombie : public Entity
{
public:
	Zombie(float x = 0.f, float y = 0.f);
	Zombie(Vector2D position);

	Vector2D getDir() const;

	void chase(const Entity& target);
	void update();

private:
	Vector2D targetPosition;
	Vector2D dir = Vector2D(0,0);

	float move_speed;

};