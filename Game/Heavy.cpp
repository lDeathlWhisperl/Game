#include "Heavy.h"
#include <iostream>

void Heavy::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'H';
}

void Heavy::move_to(Point pnt)
{
	if (std::abs((pnt - coords).x + (pnt - coords).y) == 1)
		coords = pnt;
}