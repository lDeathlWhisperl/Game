#include "Heavy.h"
#include <iostream>

void Heavy::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'H';
}

void Heavy::move_to(Point pnt)
{
	coords = pnt;
}