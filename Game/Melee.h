#pragma once
#include "Unit.h"

// Первый тип юнитов - ближний бой

class Melee : public Unit
{
public:
	Melee(int hp, int str, int arm, int cost) : Unit(hp, str, arm, cost) {}
};

