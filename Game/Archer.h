#pragma once
#include "Range.h"

// –еализаци€ вида юнита. ќбрати внимание, что методы (*) имеют свою реализацию (в файле Melee.cpp). Ёто означает, что данный класс уже 
// не €вл€етс€ абстрактным и может иметь свои экземпл€ры (то есть это обычный класс)

class Archer : public Range
{
public:
	Archer() : Range(3, 1, 0, 2) 
	{
		name = "Archer";
	}

	void draw();

	void move_to(Point);
};

