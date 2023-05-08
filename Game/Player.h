#pragma once
#include "Point.h"

class Player
{
	int money;
	Point coords;
public:
	Player() : money(0), coords({ 1, 1 }) {}

	void draw();

	void controller();
};

