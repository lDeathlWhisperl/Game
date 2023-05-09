#pragma once

#include "Swordsman.h"	//lvl 1
#include "Archer.h"		//

#include "Heavy.h"		//lvl 2
#include "Crossbower.h"	//

class Spawner
{
public:
	virtual Range* spawn_range() = 0;
	virtual Melee* spawn_melee() = 0;
};

