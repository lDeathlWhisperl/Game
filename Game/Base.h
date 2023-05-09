#pragma once
#include "Player.h"
#include "Point.h"
#include "Unit.h"

#include <list>

class Base
{
	Point coords;
	int menu_id = 0, unit_lvl = 0, unit_type = 0;
	bool isShopActive = true;
	std::list<Unit*> units;

public:
	Base() : coords({1, 1}) {}

	void draw();

	void shop(Player&);
private:
	void menu_melee();
	void controller_menu_melee(bool&);
	void select_menu_melee(bool&);

	void menu_range();
	void controller_menu_range(bool&);
	void select_menu_range(bool&);

	void menu();
	void controller_menu();
	void select_menu();

	Unit* spawn(int, int);
};

