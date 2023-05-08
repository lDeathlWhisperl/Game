#include "Archer.h"
#include <iostream>

void Archer::draw()
{
	std::cout << 'A';
}

void Archer::move_to(Point pnt)
{
	coords = pnt;
}