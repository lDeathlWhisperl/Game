#pragma once
#include "Player.h"

class Field
{
	friend Player; // не уверен, что это хороший тон, однако сделал я это для того, чтобы в Player'е был доступ к размерам поля
	static int length, width;
public:
	Field(int l, int w) 
	{
		length = l;
		width = w;
	}

	void draw();
};

