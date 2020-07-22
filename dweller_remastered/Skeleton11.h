#pragma once
#include "Inclusion.h"
#include "Resources.h"
#include "Unit.h"

class Skeleton11 : public Unit
{
private:
	void interact(int toX, int toY);
	int meleeAtack();
public:
	Skeleton11();
	void update();
};

Skeleton11* skeleton11Cast(void* ptr);