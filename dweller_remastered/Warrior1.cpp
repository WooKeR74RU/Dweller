#include "Warrior1.h"

int Warrior1::meleeAtack()
{
	return 1;
}

void Warrior1::update()
{
	if (Input::pressed(Keyboard::W))
		interact(x, y - 1);
	if (Input::pressed(Keyboard::E))
		interact(x + 1, y - 1);
	if (Input::pressed(Keyboard::D))
		interact(x + 1, y);
	if (Input::pressed(Keyboard::C))
		interact(x + 1, y + 1);
	if (Input::pressed(Keyboard::X))
		interact(x, y + 1);
	if (Input::pressed(Keyboard::Z))
		interact(x - 1, y + 1);
	if (Input::pressed(Keyboard::A))
		interact(x - 1, y);
	if (Input::pressed(Keyboard::Q))
		interact(x - 1, y - 1);

	Res::getOffset().first = x * Res::getBS() + Res::getBS() / 2 - Res::getResolution().first / 2;
	Res::getOffset().second = y * Res::getBS() + Res::getBS() / 2 - Res::getResolution().second / 2;

	sprite1.setPosition(x * Res::getBS() - Res::getOffset().first, y * Res::getBS() - Res::getOffset().second);
	sprite2.setPosition(x * Res::getBS() - Res::getOffset().first, y * Res::getBS() - Res::getOffset().second);
}

Warrior1::Warrior1()
{
	type = idWarrior;
	hp = 10;
	curSpr = 0;
	sprite1.setTexture(Res::getTexMonsters());
	sprite2.setTexture(Res::getTexMonsters());
	sprite1.setTextureRect(IntRect(0, 0, Res::getBS(), Res::getBS()));
	sprite2.setTextureRect(IntRect(0, Res::getBS(), Res::getBS(), Res::getBS()));
}

Warrior1* warrior1Cast(void* ptr)
{
	return (Warrior1*)(ptr);
}