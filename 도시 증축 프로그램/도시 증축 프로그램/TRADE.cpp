#include "all_includes.h"

TRADE::TRADE(void)
	:resources(0, 0, 0)
{
}

TRADE::TRADE(int AmountOfIron, int AmountOfStone, int AmountOfWood)
	:resources(AmountOfIron, AmountOfStone, AmountOfWood)
{
}

TRADE::~TRADE(void)
{
}

bool TRADE::SellToCity(Enums::SORT resource, CITY &city, int amount)
{
	if(amount < 0)
		return false;

	int price;
	switch (resource)
	{
	case Enums::IRON:
		price = resources.iron.getPrice() * amount;
		break;

	case Enums::STONE:
		price = resources.stone.getPrice() * amount;
		break;

	case Enums::WOOD:
		price = resources.wood.getPrice() * amount;
		break;
	}

	city.subMoney(price);
	this->subResources(resource, amount);
	city.addResources(resource, amount);

	return true;
}

bool TRADE::BuyFromCity(Enums::SORT resource, CITY &city, int amount)
{
	if(amount < 0)
		return false;

	int price;
	switch (resource)
	{
	case Enums::IRON:
		price = resources.iron.getPrice() * amount;
		break;

	case Enums::STONE:
		price = resources.stone.getPrice() * amount;
		break;

	case Enums::WOOD:
		price = resources.wood.getPrice() * amount;
		break;
	}

	city.addMoney(price);
	this->addResources(resource, amount);
	city.subResources(resource, amount);

	return true;
}

bool TRADE::addResources(Enums::SORT resource, int amount)
{
	if(amount < 0)
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

bool TRADE::subResources(Enums::SORT resource, int amount)
{
	if(amount < 0)
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