#include "Point.h"
#include <iostream>

void gotoPoint(Point pnt)
{
	std::cout << "\033[" << pnt.y << ";" << pnt.x << "H";
}