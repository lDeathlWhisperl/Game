#include "Crossbower.h"
#include <iostream>

void Crossbower::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'C';
}

void Crossbower::move_to(Point pnt)
{
	coords += pnt;
}