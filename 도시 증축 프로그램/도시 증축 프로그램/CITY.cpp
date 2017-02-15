#include "all_includes.h"

CITY::CITY(void)
	:population(1000), tax(100), money(10000), resources(1, 1, 1), slot_TownHall(NULL)
{
}

CITY::CITY(int population, int tax, int money, int AmountOfIron, int AmountOfStone, int AmountOfWood)
	:population(population), tax(tax), money(money), resources(AmountOfIron, AmountOfStone, AmountOfWood), slot_TownHall(NULL)
{
}

CITY::CITY(const CITY &copy)
	:population(copy.population), tax(copy.tax), money(copy.money), resources(copy.resources)
{
	if (copy.slot_TownHall != NULL)
		slot_TownHall = new TOWN_HALL(*copy.slot_TownHall);
	else
		slot_TownHall = NULL;
}

CITY::~CITY(void)
{
	if(slot_TownHall != NULL)
		delete slot_TownHall;
}

void CITY::ShowInfo(void)
{
	cout << "[���� ����]" << endl;
	cout << "- �⺻" << endl;
	cout << "�α�: " << population << "��" << endl;
	cout << "����: x" << tax << "��" << endl;
	cout << "����: " << money << "��" << endl;
	cout << "- �ڿ�" << endl;
	cout << "��ö: " << resources.iron.getAmount() << "��" << endl;
	cout << "����: " << resources.stone.getAmount() << "��" << endl;
	cout << "����: " << resources.wood.getAmount() << "��" << endl;
	cout << "- �ǹ�" << endl;
	cout << "��û: ";

	if (slot_TownHall != NULL)
		cout << slot_TownHall->getUpgrade() << "�ܰ�" << endl;
	else
		cout << "����" << endl;
	
	cout << endl;
}

bool CITY::addResources(Enums::SORT resource, int amount)
{
	if (amount < 0)
		return false;

	switch (resource)
	{
	case Enums::IRON:
		resources.iron.addAmount(amount);
		break;

	case Enums::STONE:
		resources.stone.addAmount(amount);
		break;

	case Enums::WOOD:
		resources.wood.addAmount(amount);
		break;
	}

	return true;
}

bool CITY::subResources(Enums::SORT resource, int amount)
{
	if (amount < 0)
		return false;

	switch (resource)
	{
	case Enums::IRON:
		resources.iron.subAmount(amount);
		break;

	case Enums::STONE:
		resources.stone.subAmount(amount);
		break;

	case Enums::WOOD:
		resources.wood.subAmount(amount);
		break;
	}

	return true;
}

bool CITY::addMoney(int amount)
{
	if (amount < 0)
		return false;

	money += amount;
	return true;
}

bool CITY::subMoney(int amount)
{
	if (amount < 0)
		return false;

	money -= amount;
	return true;
}

bool CITY::Build(Enums::SORT building)
{
	switch (building)
	{
	case Enums::TOWN_HALL:
		subResources(Enums::IRON, TOWN_HALL::RequiredIron);
		subResources(Enums::STONE, TOWN_HALL::RequiredStone);
		subResources(Enums::WOOD, TOWN_HALL::RequiredWood);
		
		if (slot_TownHall == NULL)
			slot_TownHall = new TOWN_HALL;
		else
			slot_TownHall->plusUpgrade();

		break;
	}

	return true;
}