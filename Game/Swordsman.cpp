#include "Swordsman.h"
#include <iostream>

void Swordsman::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'S';
}

void Swordsman::move_to(Point pnt)
{
	if (std::abs((pnt - coords).x + (pnt - coords).y) == 1)
		coords = pnt;
}