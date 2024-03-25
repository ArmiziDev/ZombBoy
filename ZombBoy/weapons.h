#pragma once
#include "entity.h"

class Weapons : public Entity
{
public:
	Weapons();

	void update();


	

private:
	Entity owner;
	Vector2D position;
};