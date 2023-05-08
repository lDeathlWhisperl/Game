#include "Player.h"
#include <iostream>
#include <conio.h>

void Player::draw()
{
	std::cout << 'P';
}

void Player::controller()
{
	char ch = '\0';

	if (_kbhit()) ch = _getch();

	switch (ch)
	{
	case 'w':
	case 'W':
		--coords.y;
		break;
	case 's':
	case 'S':
		++coords.y;
		break;
	case 'a':
	case 'A':
		--coords.x;
		break;
	case 'd':
	case 'D':
		++coords.x;
		break;
	}
}