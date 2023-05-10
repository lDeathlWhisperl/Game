#pragma once
#include "Landscape.h"

class Forest : public Landscape
{
public:               
	Forest(int length, int width, int seed) : Landscape(length, width, seed) {}
	void draw();
};

