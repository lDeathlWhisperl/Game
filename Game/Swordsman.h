#pragma once
#include "Melee.h"

class Swordsman : public Melee
{
public:
	Swordsman() : Melee(3, 1, 1, 1) {}

	void draw();

	void move_to(Point);
};

