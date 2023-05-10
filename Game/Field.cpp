#include "Field.h"
#include "Point.h"

#include "Desert.h"
#include "Forest.h"
#include "Tundra.h"

#include <iostream>

int Field::length, Field::width;

Field::Field(int l, int w, char ty) : type(ty)
{
	length = l;
	width = w;

	switch (type)
	{
	case 'd':
	case 'D':
		lnd = new Desert(length, width, seed);
		break;
	case 'f':
	case 'F':
		lnd = new Forest(length, width, seed);
		break;
	case 't':
	case 'T':
		lnd = new Tundra(length, width, seed);
		break;
	default:
		empty();
	}
}

void Field::draw()
{
	lnd->draw();
}

void Field::empty()
{
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < length; ++x)
		{
			if (x % (length - 1) == 0 || y % (width - 1) == 0) std::cout << "X ";
			else std::cout << "  ";
		}
		std::cout << '\n';
	}
}