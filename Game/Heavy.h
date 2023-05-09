#pragma once
#include "Melee.h"

// –еализаци€ вида юнита. ќбрати внимание, что методы (*) имеют свою реализацию (в файле Melee.cpp). Ёто означает, что данный класс уже 
// не €вл€етс€ абстрактным и может иметь свои экземпл€ры (то есть это обычный класс)

class Heavy : public Melee
{
public:
	Heavy() : Melee(1, 1, 3, 4) {}

	void draw();

	void move_to(Point);
};

