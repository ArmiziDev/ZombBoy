#pragma once

#include "Vector2D.h"

class Hitbox {
public:
	Vector2D position;
	Vector2D size;

	Hitbox() {}
	Hitbox(Vector2D pos, Vector2D size) : position(pos), size(size) {}

	void updatePosition(Vector2D pos) {
		position = pos;
	}

	void setSize(Vector2D size) {
		size = size;
	}

	bool intersects(const Hitbox& other) const {

		bool collisionX = position.x + size.x > other.position.x &&
			other.position.x + other.size.x > position.x;
		bool collisionY = position.y + size.y > other.position.y &&
			other.position.y + other.size.y > position.y;
		return collisionX && collisionY;
	}



};