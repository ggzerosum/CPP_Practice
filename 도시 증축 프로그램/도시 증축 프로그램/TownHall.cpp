#include "all_includes.h"

int TOWN_HALL::RequiredIron = TownHall_RequiredIron;
int TOWN_HALL::RequiredStone = TownHall_RequiredStone;
int TOWN_HALL::RequiredWood = TownHall_RequiredWood;

TOWN_HALL::TOWN_HALL(void)
	:upgrade(1)
{
}

TOWN_HALL::~TOWN_HALL(void)
{
}

int TOWN_HALL::getRequiredResource(Enums::SORT resource)
{
	switch (resource)
	{
	case Enums::IRON:
		return RequiredIron;

	case Enums::STONE:
		return RequiredStone;

	case Enums::WOOD:
		return RequiredWood;
	}

	return 0;
}

int TOWN_HALL::getUpgrade(void)
{
	return upgrade;
}

void TOWN_HALL::plusUpgrade(void)
{
	upgrade++;
}