#pragma once
#include "Melee.h"

// ���������� ���� �����. ������ ��������, ��� ������ (*) ����� ���� ���������� (� ����� Melee.cpp). ��� ��������, ��� ������ ����� ��� 
// �� �������� ����������� � ����� ����� ���� ���������� (�� ���� ��� ������� �����)

class Heavy : public Melee
{
public:
	Heavy() : Melee(1, 1, 3, 4) {}

	void draw();

	void move_to(Point);
};

