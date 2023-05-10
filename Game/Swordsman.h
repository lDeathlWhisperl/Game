#pragma once
#include "Melee.h"

// ���������� ���� �����. ������ ��������, ��� ������ (*) ����� ���� ���������� (� ����� Melee.cpp). ��� ��������, ��� ������ ����� ��� 
// �� �������� ����������� � ����� ����� ���� ���������� (�� ���� ��� ������� �����)

class Swordsman : public Melee
{
public:
	Swordsman() : Melee(3, 1, 1, 1) 
	{
		name = "Swordsman";
	}

	void draw();

	void move_to(Point);
};

