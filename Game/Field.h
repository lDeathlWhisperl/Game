#pragma once
#include "Player.h"
#include "Landscape.h"

class Field
{
	friend Player; // не уверен, что это хороший тон, однако сделал я это для того, чтобы в Player'е был доступ к размерам поля
	int seed = 22565; // можешь ввести любое число, это сид генерации
	static int length, width;
	char type;
	Landscape* lnd = nullptr;
public:
	Field(int, int, char = '\0');
	
	void draw();
private:
	void empty();
};

