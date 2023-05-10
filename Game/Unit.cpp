#include "Unit.h"

void Unit::setCoords(Point pnt)
{
	coords = pnt;
}

int Unit::getCost()
{
	return cost;
}

Point Unit::getCoords()
{
	return coords;
}

std::ostream& operator<<(std::ostream& out, const Unit* u)
{
	out << "Type:....." << u->name << '\n'
		<< "HP:......." << u->HP << '\n'
		<< "Strength:." << u->strength << '\n'
		<< "Armor:...." << u->armor << '\n'
		<< "Cost:....." << u->cost << '\n';

	return out;
}
