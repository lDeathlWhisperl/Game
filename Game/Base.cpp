#include "Base.h"
#include "Lvl_1.h"
#include "Lvl_2.h"

#include <iostream>
#include <conio.h>

void Base::draw()
{
	gotoPoint({ coords.x + 1, coords.y + 1 });
	std::cout << 'B';

	if (!units.empty())
		for (Unit* u : units)
			u->draw();
}

void Base::shop(Player& player)
{
	if (player.lastPressedKey() != ' ') return; // если не был нажат пробел (вход в меню покупок на базе)
	if (player.getCoords() != coords) return;  // если мы находимся за пределами базы

	isShopActive = true;

	while (isShopActive) // отрисовка меню и кнопок магазина (тут можно не вникать в суть, просто для красоты. но можешь попробовать на свой страх и риск :)) 
	{
		gotoPoint({ 0, 27 });
		std::cout << "Welcome to unishop!\n\n";

		menu();
		controller_menu();
	}
}

void Base::menu()
{
	char menu[][24] = { "[ melee warriors ]\x1b[0m\n",
						"[ range warriors ]\x1b[0m\n",
						"[      exit      ]\x1b[0m\n"};

	for (int i = 0; i < 3; ++i)
	{
		if (i == menu_id) std::cout << "\x1b[44m";
		std::cout << menu[i];
	}
}
void Base::controller_menu()
{
	switch (_getch())
	{
	case 'w':
	case 'W':
		if (menu_id != 0) --menu_id;
		break;
	case 's':
	case 'S':
		if (menu_id != 2) ++menu_id;
		break;
	case ' ':
		select_menu();
		break;
	}
}
void Base::select_menu()
{
	bool isExit = false;
	int temp_id = menu_id;

	switch (menu_id)
	{
	case 0:
		unit_type = 1;
		menu_id = 0;
		while(!isExit)
		{
			gotoPoint({ 0, 27 });
			std::cout << "Melee warriors list:\n\n";

			menu_melee();
			controller_menu_melee(isExit);
		}
		break;
	case 1:
		unit_type = 2;
		menu_id = 0;
		while (!isExit)
		{
			gotoPoint({ 0, 27 });
			std::cout << "Range warriors list:\n\n";

			menu_range();
			controller_menu_range(isExit);
		}
		break;
	case 2:
		isShopActive = false;
		system("cls");
		std::cout << "Bye!";
		break;
	}
	menu_id = temp_id;
}

void Base::menu_melee()
{
	char menu[][18] = { "[ swordsman ]\x1b[0m",
						"[   heavy   ]\x1b[0m",
						"[    exit   ]\x1b[0m" };

	for (int i = 0; i < 3; ++i)
	{
		if (i == menu_id) std::cout << "\x1b[44m";
		std::cout << menu[i];

		if (i == menu_id && menu_id < 2)std::cout << " -> cost: " << spawn(i+1, unit_type)->getCost();
		else std::cout << "           ";

		std::cout << '\n';
	}
}
void Base::controller_menu_melee(bool& isExit)
{
	switch (_getch())
	{
	case 'w':
	case 'W':
		if (menu_id != 0) --menu_id;
		break;
	case 's':
	case 'S':
		if (menu_id != 2) ++menu_id;
		break;
	case ' ':
		select_menu_melee(isExit);
		break;
	}
}
//unfinished
void Base::select_menu_melee(bool& isExit)
{
	switch (menu_id)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:
		isExit = true;
		break;
	}
}

void Base::menu_range()
{
	char menu[][19] = { "[   archer   ]\x1b[0m",
						"[ crossbower ]\x1b[0m",
						"[    exit    ]\x1b[0m" };

	for (int i = 0; i < 3; ++i)
	{
		if (i == menu_id) std::cout << "\x1b[44m";
		std::cout << menu[i];

		if (i == menu_id && menu_id < 2)std::cout << " -> cost: " << spawn(i+1, unit_type)->getCost();
		else std::cout << "           ";

		std::cout << '\n';
	}
}
void Base::controller_menu_range(bool& isExit)
{
	switch (_getch())
	{
	case 'w':
	case 'W':
		if (menu_id != 0) --menu_id;
		break;
	case 's':
	case 'S':
		if (menu_id != 2) ++menu_id;
		break;
	case ' ':
		select_menu_range(isExit);
		break;
	}
}
//unfinished
void Base::select_menu_range(bool& isExit)
{
	switch (menu_id)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:
		isExit = true;
		break;
	}
}

Unit* Base::spawn(int lvl, int type)
{
	Unit* unit;
	Spawner* spawner;

	switch (lvl)
	{
	case 1:
		spawner = new Lvl_1();
		break;
	default:
		spawner = new Lvl_2();
	}

	switch (type)
	{
	case 1:
		unit = spawner->spawn_melee();
		break;
	default:
		unit = spawner->spawn_range();
	}
	delete spawner;
	return unit;
}