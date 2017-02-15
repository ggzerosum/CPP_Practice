#pragma once
class TRADE
{
private:
	RESOURCES resources;
public:
	TRADE(void);
	TRADE(int AmountOfIron, int AmountOfStone, int AmountOfWood);
	~TRADE(void);
public:
	bool SellToCity(Enums::SORT resource, CITY &city, int amount);
	bool BuyFromCity(Enums::SORT resource, CITY &city, int amount);
	bool addResources(Enums::SORT resource, int amount);
	bool subResources(Enums::SORT resource, int amount);
};

