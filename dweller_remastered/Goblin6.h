#pragma once
#include "Inclusion.h"
#include "Resources.h"
#include "Unit.h"

class Goblin6 : public Unit
{
private:
	void interact(int toX, int toY);
	int meleeAtack();
public:
	Goblin6();
	void update();
};

Goblin6* goblin6Cast(void* ptr);