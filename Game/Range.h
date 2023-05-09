#pragma once
#include "Unit.h"

class Range : public Unit
{
public:
	Range(int hp, int str, int arm, int cost) : Unit(hp, str, arm, cost) {}
};

