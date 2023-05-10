#include "Forest.h"
#include <iostream>

void Forest::draw()
{
	srand(seed);
	for (int y = 0; y < width; ++y)
	{
		for (int x = 0; x < length; ++x)
		{
			if (x == 0 && (y > 0 && y < width - 1))
				std::cout << "X\x1b[92m" << (char)219 << "\x1b[0m";
			else if (x % (length - 1) == 0 || y % (width - 1) == 0)
				std::cout << "X ";
			else if (getRandomNumber(0, 100) < 6)
				std::cout << "\x1b[36m" << (char)219 << (char)219 << "\x1b[0m";
			else if (getRandomNumber(0, 100) < 25)
				std::cout << "\x1b[32m" << (char)219 << (char)219 << "\x1b[0m";
			else
				std::cout << "\x1b[92m" << (char)219 << (char)219 << "\x1b[0m";
		}
		std::cout << '\n';
	}
}