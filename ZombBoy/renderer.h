#pragma once

#include <unordered_map>

#include "entity.h"


class Render 
{
public:
	int total;


	std::unordered_map<int, Entity> entities;

	void render();


private:
	

};

