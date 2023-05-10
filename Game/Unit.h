#pragma once
#include "Point.h"
#include <iostream>

// общий класс для всех типов юнитов. От него наследуются ТИПЫ юнитов, т.е. классы Melee(ближний бой) и Range(дальний бой).
// Здесь описаны все основные характеристики: здоровье, сила, защита и стоимось
// Этот класс является абстрактным из-за наличия чисто-виртуальных методов (*) - это означает, что экземпляр этого класс не может быть создан,
// может быть создан лишь указатель на этот класс. Отсюда начинается реализация паттерна "абстрактная фабрика".

class Unit
{
protected:
	int HP, strength, armor, cost;
	Point coords = { 1,1 };
	std::string name = "";
public:
	Unit(int hp, int str, int arm, int c) : HP(hp), strength(str), armor(arm), cost(c) {}

	virtual void draw() = 0; // *
	virtual void move_to(Point) = 0; // *
	virtual int getCost();
	void setCoords(Point);
	Point getCoords();

	friend std::ostream& operator<<(std::ostream&, const Unit*);
};

