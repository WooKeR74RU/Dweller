#include "Unit.h"

void Unit::damage(int val)
{
	hp -= val;
}
void Unit::nextSprite()
{
	curSpr = !curSpr;
}
const Sprite& Unit::getSprite()
{
	if (!curSpr)
		return sprite1;
	else
		return sprite2;
}
const int Unit::getType()
{
	return type;
}