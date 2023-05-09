#pragma once

struct Point
{
	int x, y;

	Point operator-(Point pnt)
	{
		return { x - pnt.x, y - pnt.y };
	}

	bool operator!=(Point pnt)
	{
		return x != pnt.x || y != pnt.y;
	}
};

void gotoPoint(Point = {0,0});