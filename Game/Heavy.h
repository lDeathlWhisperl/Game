#pragma once
#include "Melee.h"

class Heavy : public Melee
{
public:
	Heavy() : Melee(1, 1, 3, 4) {}

	void draw();

	void move_to(Point);
};

