#pragma once
#include "Inclusion.h"
#include "Resources.h"
#include "Input.h"
#include "Unit.h"

class Warrior1 : public Unit
{
private:
	void interact(int toX, int toY);
	int meleeAtack();
public:
	Warrior1();
	void update();
};

Warrior1* warrior1Cast(void* ptr);