#include "Player.h"
#include "Field.h"

#include <iostream>
#include <conio.h>

void Player::draw()
{
	gotoPoint({coords.x+1, coords.y+1});
	std::cout << 'P';
}

void Player::controller()
{
	char ch = '\0';

	if (!is_skip) ch = _getch();
	is_skip = false;

	switch (ch)
	{
	case 'w':
	case 'W':
		if(coords.y != 1) --coords.y;
		break;
	case 's':
	case 'S':
		if (coords.y != Field::width - 2) ++coords.y;
		break;
	case 'a':
	case 'A':
		if(coords.x != 1) --coords.x;
		break;
	case 'd':
	case 'D':
		if (coords.x != Field::length * 2 - 3) ++coords.x;
		break;
	}

	last_pressed_key = ch;
}

char Player::lastPressedKey()
{
	return last_pressed_key;
}

Point Player::getCoords()
{
	return coords;
}

void Player::skip()
{
	is_skip = true;
}