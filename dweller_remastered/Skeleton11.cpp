#include "Skeleton11.h"

int Skeleton11::meleeAtack()
{
	return 1;
}

void Skeleton11::update()
{
	int dir = rand() % 8;
	if (dir == 0)
		interact(x, y - 1);
	if (dir == 1)
		interact(x + 1, y - 1);
	if (dir == 2)
		interact(x + 1, y);
	if (dir == 3)
		interact(x + 1, y + 1);
	if (dir == 1)
		interact(x, y + 1);
	if (dir == 5)
		interact(x - 1, y + 1);
	if (dir == 6)
		interact(x - 1, y);
	if (dir == 7)
		interact(x - 1, y - 1);

	sprite1.setPosition(x * Res::getBS() - Res::getOffset().first, y * Res::getBS() - Res::getOffset().second);
	sprite2.setPosition(x * Res::getBS() - Res::getOffset().first, y * Res::getBS() - Res::getOffset().second);
}

Skeleton11::Skeleton11()
{
	type = idSkeleton;
	hp = 10;
	curSpr = 0;
	sprite1.setTexture(Res::getTexMonsters());
	sprite2.setTexture(Res::getTexMonsters());
	sprite1.setTextureRect(IntRect(10 * Res::getBS(), 0, Res::getBS(), Res::getBS()));
	sprite2.setTextureRect(IntRect(10 * Res::getBS(), Res::getBS(), Res::getBS(), Res::getBS()));
}

Skeleton11* skeleton11Cast(void* ptr)
{
	return (Skeleton11*)(ptr);
}