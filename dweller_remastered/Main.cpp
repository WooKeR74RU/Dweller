#include "Inclusion.h"
#include "Resources.h"
#include "Input.h"
#include "Warrior1.h"
#include "Goblin6.h"
#include "Skeleton11.h"

int main()
{
	srand(time(0));
	Clock clock;

	Res::getResolution() = make_pair(800, 600);
	//Res::getResolution() = make_pair(1152, 864);
	Res::getWindow().create(VideoMode(Res::getResolution().first, Res::getResolution().second), "Dweller", Style::Close);
	{
		Image icon;
		icon.loadFromFile("textures/icon32.png");
		Res::getWindow().setIcon(32, 32, icon.getPixelsPtr());
	}
	Res::getBS() = 48;
	Res::getTexMonsters().loadFromFile("textures/monsters_48x48.png");
	Res::getTexWorld().loadFromFile("textures/world_48x48.png");
	Res::loadMap("maps/map.txt");

	Warrior1 player;
	player.id = 0;
	player.x = 1;
	player.y = 1;

	Goblin6 goblin;
	goblin.id = 1;
	goblin.x = 1;
	goblin.y = 3;

	Skeleton11 skelet1;
	skelet1.id = 2;
	skelet1.x = 2;
	skelet1.y = 4;

	Skeleton11 skelet2;
	skelet2.id = 3;
	skelet2.x = 2;
	skelet2.y = 7;

	auto units = &Res::getUnits();
	units->resize(4);
	(*units)[0] = UnitPtr(&player, idWarrior);
	(*units)[1] = UnitPtr(&goblin, idGoblin);
	(*units)[2] = UnitPtr(&skelet1, idSkeleton);
	(*units)[3] = UnitPtr(&skelet2, idSkeleton);
	
	auto unitsId = &Res::getUnitsId();
	(*unitsId)[1][1].push_back(0);
	(*unitsId)[3][1].push_back(1);
	(*unitsId)[4][2].push_back(2);
	(*unitsId)[7][2].push_back(3);

	for (int i = 0; i < (*units).size(); i++)
		(*units)[i].update();

	auto window = &Res::getWindow();

	while (1)
	{
		Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				(*window).close();
				return 0;
			}
		}

		Input::update();
		if (!Input::wait())
		{
			for (int i = 0; i < (*units).size(); i++)
				(*units)[i].update();
		}

		double dt = clock.restart().asMicroseconds() / 1000;
		static double timeAnim = 0;
		timeAnim += dt;
		if (timeAnim > 1000)
		{
			for (int i = 0; i < (*units).size(); i++)
				(*units)[i].nextSprite();
			timeAnim = 0;
		}

		(*window).clear();
		Res::drawMap();
		for (int i = 0; i < (*units).size(); i++)
			(*window).draw((*units)[i].getSprite());
		(*window).display();
	}

	return 0;
}