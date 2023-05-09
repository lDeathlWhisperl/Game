#include "Archer.h"
#include <iostream>

void Archer::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'A';
}

void Archer::move_to(Point pnt)
{
	if (std::abs((pnt - coords).x + (pnt - coords).y) == 1)
		coords = pnt;
}