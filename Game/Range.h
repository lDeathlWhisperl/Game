#pragma once
#include "Unit.h"

class Range : public Unit
{
public:
	Range(int hp, int str, int cost, Point coords) : Unit(hp, str, cost, coords) {}
};

