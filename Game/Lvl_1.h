#pragma once
#include "Spawner.h"

// �� �������� ������ ������������, ��� ������� ������ "����������" ������ ������� �����. ������ ����� ������ (� Lvl_2) - �����������
// ����������� ������ ���������� ������ Spawner

class Lvl_1 : public Spawner
{
public:
	Range* spawn_range()
	{
		return new Archer();
	}

	Melee* spawn_melee()
	{
		return new Swordsman();
	}
};

