#pragma once
class CITY
{
private:
	int population;
	int tax;
	int money;
	RESOURCES resources;
	TOWN_HALL* slot_TownHall;
public:
	CITY(void);
	CITY(int population, int tax, int money, int AmountOfIron, int AmountOfStone, int AmountOfWood);
	CITY(const CITY &copy);
	~CITY(void);
public:
	void ShowInfo(void);
	bool addResources(Enums::SORT resource, int amount);
	bool subResources(Enums::SORT resource, int amount);
	bool addMoney(int amount);
	bool subMoney(int amount);
	bool Build(Enums::SORT building);
};

