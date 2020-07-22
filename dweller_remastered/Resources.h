#pragma once
#include "Inclusion.h"

struct UnitPtr
{
	void* ptr;
	int type;
	UnitPtr();
	UnitPtr(void* _ptr, int _type);
	void update();
	const Sprite& getSprite();
	void nextSprite();
};

namespace Res
{
	RenderWindow& getWindow();
	pair<int, int>& getResolution();
	vector<vector<int>>& getField();
	vector<UnitPtr>& getUnits();
	vector<vector<vector<int>>>& getUnitsId();
	int& getBS();
	Texture& getTexMonsters();
	Texture& getTexWorld();
	pair<int, int>& getOffset();

	void loadMap(const string &link);
	void drawMap();
}