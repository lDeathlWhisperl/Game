#include "Landscape.h"
#include <iostream>

int Landscape::getRandomNumber(int min, int max)
{
	return min + rand() % (max - min + 1);
}