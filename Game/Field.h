#pragma once
#include "Player.h"

class Field
{
	friend Player;
	static int length, width;
public:
	Field(int l, int w) 
	{
		length = l;
		width = w;
	}

	void draw();
};

