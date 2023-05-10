#include "Archer.h"
#include <iostream>

void Archer::draw()
{
	gotoPoint({ coords.x + 1,coords.y + 1 });
	std::cout << 'A';
}

void Archer::move_to(Point pnt)
{
	coords += pnt;
}