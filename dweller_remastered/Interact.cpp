#include "Resources.h"
#include "Warrior1.h"
#include "Goblin6.h"
#include "Skeleton11.h"

UnitPtr::UnitPtr()
{}
UnitPtr::UnitPtr(void* _ptr, int _type)
{
	ptr = _ptr;
	type = _type;
}
void UnitPtr::update()
{
	if (type == idWarrior)
		warrior1Cast(ptr)->update();
	if (type == idGoblin)
		goblin6Cast(ptr)->update();
	if (type == idSkeleton)
		skeleton11Cast(ptr)->update();
}
const Sprite& UnitPtr::getSprite()
{
	if (type == idWarrior)
		return warrior1Cast(ptr)->getSprite();
	if (type == idGoblin)
		return goblin6Cast(ptr)->getSprite();
	if (type == idSkeleton)
		return skeleton11Cast(ptr)->getSprite();
}
void UnitPtr::nextSprite()
{
	if (type == idWarrior)
		warrior1Cast(ptr)->nextSprite();
	if (type == idGoblin)
		goblin6Cast(ptr)->nextSprite();
	if (type == idSkeleton)
		skeleton11Cast(ptr)->nextSprite();
}

////////////////////////////////////////////////////////////////////////////////

void hit(UnitPtr &target, int val)
{
	if (target.type == idWarrior)
		warrior1Cast(target.ptr)->damage(val);
	if (target.type == idGoblin)
		goblin6Cast(target.ptr)->damage(val);
	if (target.type == idSkeleton)
		skeleton11Cast(target.ptr)->damage(val);
}

void delType(int type, int x, int y)
{
	auto unitsId = &Res::getUnitsId();
	auto units = &Res::getUnits();
	for (int i = 0; i < (*unitsId)[y][x].size(); i++)
	{
		int curId = (*unitsId)[y][x][i];
		if ((*units)[curId].type == type)
		{
			(*unitsId)[y][x].erase((*unitsId)[y][x].begin() + i);
			return;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void Warrior1::interact(int toX, int toY)
{
	auto field = &Res::getField();
	if ((*field)[toY][toX] == idWall)
	{
		cout << "Wall" << endl;
		return;
	}
	
	auto units = &Res::getUnits();
	auto unitsId = &Res::getUnitsId();

	for (int i = 0; i < (*unitsId)[toY][toX].size(); i++)
	{
		int curId = (*unitsId)[toY][toX][i];
		hit((*units)[curId], meleeAtack());

		cout << "Hit!" << endl;
	}

	if ((*unitsId)[toY][toX].empty())
	{
		cout << "Step" << endl;

		curSpr = 0;
		delType(type, x, y);
		x = toX;
		y = toY;
		(*unitsId)[toY][toX].push_back(id);
	}
}

void Goblin6::interact(int toX, int toY)
{
	auto field = &Res::getField();
	if ((*field)[toY][toX] == idWall)
		return;

	auto units = &Res::getUnits();
	auto unitsId = &Res::getUnitsId();

	for (int i = 0; i < (*unitsId)[toY][toX].size(); i++)
	{
		int curId = (*unitsId)[toY][toX][i];
		hit((*units)[curId], meleeAtack());

		cout << "Goblin Hit!" << endl;
	}

	if ((*unitsId)[toY][toX].empty())
	{
		curSpr = 0;
		delType(type, x, y);
		x = toX;
		y = toY;
		(*unitsId)[toY][toX].push_back(id);
	}
}

void Skeleton11::interact(int toX, int toY)
{
	auto field = &Res::getField();
	if ((*field)[toY][toX] == idWall)
		return;

	auto units = &Res::getUnits();
	auto unitsId = &Res::getUnitsId();

	for (int i = 0; i < (*unitsId)[toY][toX].size(); i++)
	{
		int curId = (*unitsId)[toY][toX][i];
		hit((*units)[curId], meleeAtack());

		cout << "Skeleton Hit!" << endl;
	}

	if ((*unitsId)[toY][toX].empty())
	{
		curSpr = 0;
		delType(type, x, y);
		x = toX;
		y = toY;
		(*unitsId)[toY][toX].push_back(id);
	}
}