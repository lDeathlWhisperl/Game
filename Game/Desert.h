#pragma once
#include "Landscape.h"

class Desert : public Landscape
{
public:
	Desert(int length, int width, int seed) : Landscape(length, width, seed) {}
	void draw();
};
