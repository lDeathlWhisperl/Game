#include "Base.h"
#include "Lvl_1.h"
#include "Lvl_2.h"

#include <iostream>
#include <conio.h>

void Base::draw()
{
	gotoPoint({ coords.x + 1, coords.y + 1 });
	std::cout << 'B';

	selected = NULL;
	if (!units.empty())
		for (Unit* u : units)
		{
			u->draw();
			if (p_copy && u->getCoords() == p_copy->getCoords())
				selected = u;
		}

	if (!selected || p_copy->lastPressedKey() != 32) return;
	
	isShopActive = true;
	menu_id = 0;

	clear();

	while (isShopActive)
	{
		gotoPoint();
		menu_unit_info();
		controller_unit_info();
	}
}

void Base::shop(Player& player)
{
	if (player.lastPressedKey() != ' ') return; // если не был нажат пробел (вход в меню покупок на базе)
	if (player.getCoords() != coords) return;  // если мы находимся за пределами базы

	p_copy = &player;
	isShopActive = true;
	menu_id = 0;
	// отрисовка меню и кнопок магазина (тут можно не вникать в суть, просто для красоты. но можешь попробовать на свой страх и риск :)) 
	// из важного стоит лишь взглянуть на метод spawn
	clear();
	while (isShopActive)
	{
		gotoPoint();
		std::cout << "Welcome to unishop! \n\n";

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
			gotoPoint();
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
			gotoPoint();
			std::cout << "Range warriors list:\n\n";

			menu_range();
			controller_menu_range(isExit);
		}
		break;
	case 2:
		isShopActive = false;

		system("cls");
		std::cout << "Bye!";
		_getch();
		p_copy->skip();
		break;
	}
	menu_id = temp_id;
}

void Base::menu_melee()
{
	char menu[][18] = { "[ swordsman ]\x1b[0m",
						"[   heavy   ]\x1b[0m",
						"[    back   ]\x1b[0m" };

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
void Base::select_menu_melee(bool& isExit)
{
	switch (menu_id)
	{
	case 0:
		units.push_back(spawn(1, unit_type));
		setCoords();
		break;
	case 1:
		units.push_back(spawn(2, unit_type));
		setCoords();
		break;
	case 2:
		isExit = true;
		break;
	}
	clear();
}

void Base::menu_range()
{
	char menu[][19] = { "[   archer   ]\x1b[0m",
						"[ crossbower ]\x1b[0m",
						"[    back    ]\x1b[0m" };

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
void Base::select_menu_range(bool& isExit)
{
	switch (menu_id)
	{
	case 0:
		units.push_back(spawn(1, unit_type));
		setCoords();
		break;
	case 1:
		units.push_back(spawn(2, unit_type));
		setCoords();
		break;
	case 2:
		isExit = true;
		break;
	}
	clear();
}

void Base::menu_unit_info()
{
	char menu[][16] = { "[  info  ]\x1b[0m\n",
						"[  move  ]\x1b[0m\n",
						"[ delete ]\x1b[0m\n",
						"[  exit  ]\x1b[0m\n"};

	for (int i = 0; i < 4; ++i)
	{
		if (i == menu_id) std::cout << "\x1b[44m";
		std::cout << menu[i];
	}
}
void Base::controller_unit_info()
{
	switch (_getch())
	{
	case 'w':
	case 'W':
		if (menu_id != 0) --menu_id;
		break;
	case 's':
	case 'S':
		if (menu_id != 3) ++menu_id;
		break;
	case ' ':
		select_unit_info();
		break;
	}
}
void Base::select_unit_info()
{
	switch (menu_id)
	{
	case 0:
		gotoPoint();
		std::cout << selected;

		_getch();
		clear();
		break;
	case 1:
		clear();
		gotoPoint();
		std::cout << "Choose the direction (w,a,s,d)";
		selected->move_to(direction());
		clear();
		break;
	case 2:
		units.remove(selected);
		isShopActive = false;
		p_copy->skip();
		break;
	case 3:
		isShopActive = false;
		p_copy->skip();
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
void Base::setCoords()
{
	gotoPoint({ 0, 0 });
	for (int i = 1; i <= 6; ++i)
		std::cout << "                         \n";
	gotoPoint({ 0, 0 });

	int x, y;
	std::cout << "set unit coords: ";
	std::cin >> x >> y;

	if (x >= length) x = length*2 - 3;
	if (x <= 0) x = 2;

	if (y >= width-1) y = width - 2;
	if (y <= 0) y = 2;

	units.back()->setCoords({ x, y });
}
Point Base::direction()
{
	Point direction = { 0,0 };
	switch (_getch())
	{
	case 'w':
	case 'W':
		--direction.y;
		break;
	case 's':
	case 'S':
		++direction.y;
		break;
	case 'a':
	case 'A':
		--direction.x;
		break;
	case 'd':
	case 'D':
		++direction.x;
		break;
	}
	
	Point temp = selected->getCoords() + direction;

	if (temp.y == 0 || temp.y == width - 1)
		return { 0,0 };

	if (temp.x == 0 || temp.x == (length - 1) * 2)
		return { 0,0 };

	return direction;
}