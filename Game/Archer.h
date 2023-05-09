#pragma once
#include "Range.h"

// ���������� ���� �����. ������ ��������, ��� ������ (*) ����� ���� ���������� (� ����� Melee.cpp). ��� ��������, ��� ������ ����� ��� 
// �� �������� ����������� � ����� ����� ���� ���������� (�� ���� ��� ������� �����)

class Archer : public Range
{
public:
	Archer() : Range(3, 1, 0, 2) {}

	void draw();

	void move_to(Point);
};

