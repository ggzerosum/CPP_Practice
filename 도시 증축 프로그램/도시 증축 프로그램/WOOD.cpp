#include "all_includes.h"

const char WOOD::name[5] = "³ª¹«";
const int WOOD::price = PriceOfWood;

WOOD::WOOD()
	:amount(0)
{
}

WOOD::WOOD(int amount)
{
	if (amount < 0)
		amount = 0;

	this->amount = amount;
}

WOOD::~WOOD()
{
}

const char* WOOD::getName(void)
{
	return name;
}

int WOOD::getPrice(void)
{
	return price;
}

int WOOD::getAmount(void)
{
	return amount;
}

bool WOOD::addAmount(int amount)
{
	if (amount < 0)
		return false;

	this->amount += amount;
	return true;
}

bool WOOD::subAmount(int amount)
{
	if ((this->amount - amount) < 0)
		return false;

	this->amount -= amount;
	return true;
}