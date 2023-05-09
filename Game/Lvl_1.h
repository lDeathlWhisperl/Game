#pragma once
#include "Spawner.h"

class Lvl_1 : public Spawner
{
public:
	Range* spawn_range()
	{
		return new Archer();
	}

	Melee* spawn_melee()
	{
		return new Swordsman();
	}
};

