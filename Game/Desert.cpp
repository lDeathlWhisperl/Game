#include "Desert.h"
#include <iostream>

void Desert::draw()
{
	srand(seed);
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < length; ++x)
		{
			if (x == 0 && (y > 0 && y < width-1)) 
				std::cout << "X\x1b[93m" << (char)219 << "\x1b[0m";
			else if (x % (length - 1) == 0 || y % (width - 1) == 0) 
				std::cout << "X ";
			else if (getRandomNumber(0, 100) < 6)
				std::cout << "\x1b[33m" << (char)219 << (char)219 << "\x1b[0m";
			else
				std::cout << "\x1b[93m" << (char)219 << (char)219 << "\x1b[0m";
		}
		std::cout << '\n';
	}
}