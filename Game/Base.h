#pragma once
#include "Player.h"
#include "Point.h"
#include "Unit.h"

#include <list>

class Base
{
	Point coords;
	int menu_id = 0, unit_type = 0, width, length;
	bool isShopActive = true;
	std::list<Unit*> units;
	Unit* selected = NULL;
	Player *p_copy = NULL;
public:
	Base(int l, int w) : coords({1, 1}), width(w), length(l) {}

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

	void menu_unit_info();
	void controller_unit_info();
	void select_unit_info();

	Unit* spawn(int, int);
	void setCoords();
	Point direction();
};

