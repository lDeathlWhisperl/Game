#pragma once

#include "Swordsman.h"	//lvl 1
#include "Archer.h"		//

#include "Heavy.h"		//lvl 2
#include "Crossbower.h"	//

// Фабричный класс, именно он будет заниматься созданием новых обЪектов (в файле Base.cpp метод void Base::spawn)

class Spawner
{
public:
	virtual Range* spawn_range() = 0;
	virtual Melee* spawn_melee() = 0;
};

