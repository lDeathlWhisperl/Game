#pragma once
#include "Point.h"

class Player
{
	int money;
	char last_pressed_key;
	bool is_skip = false;
	Point coords;
public:
	Player() : money(0), coords({ 1,2 }), last_pressed_key('\0') {}

	void draw();

	void controller();

	char lastPressedKey();

	Point getCoords();

	void skip();
};

