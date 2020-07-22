#pragma once
#include "Inclusion.h"

class Unit
{
protected:
	Sprite sprite1, sprite2;
	bool curSpr;
	int type;
	int hp;
public:
	int x, y;
	int id;
	void damage(int val);
	void nextSprite();
	const int getType();
	const Sprite& getSprite();
};