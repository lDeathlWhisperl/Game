#pragma once
#include "Range.h"

// –еализаци€ вида юнита. ќбрати внимание, что методы (*) имеют свою реализацию (в файле Melee.cpp). Ёто означает, что данный класс уже 
// не €вл€етс€ абстрактным и может иметь свои экземпл€ры (то есть это обычный класс)

class Crossbower : public Range
{
public:
	Crossbower() : Range(3, 2, 2, 3) {}

	void draw();

	void move_to(Point);
};

