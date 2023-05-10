#pragma once
#include "Landscape.h"

class Tundra : public Landscape
{
public:
	Tundra(int length, int width, int seed) : Landscape(length, width, seed) {}
	void draw();
};

