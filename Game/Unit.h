#pragma once
#include "Point.h"

class Unit
{
protected:
	int HP, strength, cost;
	Point coords;
public:
	Unit(int hp, int str, int c, Point crds) : HP(hp), strength(str), cost(c), coords(crds) {}

	virtual void draw() = 0;
	virtual void move_to(Point) = 0;
};

