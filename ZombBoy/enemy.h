#pragma once

#include "entity.h"

class Zombie : public Entity
{
public:
	Zombie(float x = 0.f, float y = 0.f);
	Zombie(Vector2D position);

	void initialize();

	Vector2D getDir() const;

	void chase(Entity* target);
	void chase(std::shared_ptr<Entity> target);
	void update();

private:
	//Vector2D targetPosition;
	Vector2D dir = Vector2D(0,0);

	int damage;
	float damage_cooldown;
	float damage_timer = 0.f;

	std::shared_ptr<Entity> target = nullptr;

	float move_speed;

};