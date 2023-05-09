#pragma once
#include "Spawner.h"

// Ќе придумал ничего оригинальнее, чем назвать вторую "координату" просто уровнем юнита. «адача этого класса (и Lvl_2) - реализовать
// абстрактные методы фабричного класса Spawner

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

