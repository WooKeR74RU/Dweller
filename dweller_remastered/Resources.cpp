#include "Resources.h"

//resources
RenderWindow window;
pair<int, int> resolution;
vector<vector<int>> field;
vector<UnitPtr> units;
vector<vector<vector<int>>> unitsId;
int blockSize;
Texture texMonsters;
Texture texWorld;
pair<int, int> offset;

//link getters
RenderWindow& Res::getWindow()
{
	return window;
}
pair<int, int>& Res::getResolution()
{
	return resolution;
}
vector<vector<int>>& Res::getField()
{
	return field;
}
vector<UnitPtr>& Res::getUnits()
{
	return units;
}
vector<vector<vector<int>>>& Res::getUnitsId()
{
	return unitsId;
}
int& Res::getBS()
{
	return blockSize;
}
Texture& Res::getTexMonsters()
{
	return texMonsters;
}
Texture& Res::getTexWorld()
{
	return texWorld;
}
pair<int, int>& Res::getOffset()
{
	return offset;
}

map<int, Sprite> spriteWorld;
void Res::loadMap(const string &link)
{
	ifstream fin;
	fin.open(link);

	string theme;
	getline(fin, theme);
	if (theme == "theme 1")
	{
		spriteWorld[idWall].setTextureRect(IntRect(0, 2 * blockSize, blockSize, blockSize));
		spriteWorld[idEmpty].setTextureRect(IntRect(3 * blockSize, 2 * blockSize, blockSize, blockSize));
	}
	if (theme == "theme 2")
	{
		spriteWorld[idWall].setTextureRect(IntRect(0, 4 * blockSize, blockSize, blockSize));
		spriteWorld[idEmpty].setTextureRect(IntRect(3 * blockSize, 4 * blockSize, blockSize, blockSize));
	}
	for (auto it = spriteWorld.begin(); it != spriteWorld.end(); it++)
		(*it).second.setTexture(texWorld);

	field.push_back(vector<int>());
	int cur = 0;
	while (1)
	{
		int tmp;
		tmp = fin.get();
		if (tmp == -1)
			break;
		if (tmp == endl)
		{
			field.push_back(vector<int>());
			cur++;
		}
		else
		{
			field[cur].push_back(tmp);
		}
	}
	unitsId.resize(field.size());
	for (int i = 0; i < field.size(); i++)
		unitsId[i].resize(field[i].size());
}
void Res::drawMap()
{
	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			int x = j * blockSize;
			int y = i * blockSize;
			spriteWorld[field[i][j]].setPosition(x - offset.first, y - offset.second);
			window.draw(spriteWorld[field[i][j]]);
		}
	}
}