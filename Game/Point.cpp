#include "Point.h"
#include <iostream>

void gotoPoint(Point pnt)
{
	std::cout << "\033[" << pnt.y << ";" << pnt.x << "H";
}

void clear()
{
	gotoPoint();
	for (int i = 1; i <= 6; ++i)
		std::cout << "                               \n";
}