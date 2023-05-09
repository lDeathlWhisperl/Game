#pragma once
#include "Spawner.h"

class Lvl_2 : public Spawner
{
public:
	Range* spawn_range()
	{
		return new Crossbower();
	}

	Melee* spawn_melee()
	{
		return new Heavy();
	}
};

