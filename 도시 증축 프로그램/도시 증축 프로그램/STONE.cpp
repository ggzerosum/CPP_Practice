#include "all_includes.h"

const char STONE::name[5] = "¼®Àç";
const int STONE::price = PriceOfStone;

STONE::STONE()
	:amount(0)
{
}

STONE::STONE(int amount)
{
	if (amount < 0)
		amount = 0;

	this->amount = amount;
}

STONE::~STONE()
{
}

const char* STONE::getName(void)
{
	return name;
}

int STONE::getPrice(void)
{
	return price;
}

int STONE::getAmount(void)
{
	return amount;
}

bool STONE::addAmount(int amount)
{
	if (amount < 0)
		return false;

	this->amount += amount;
	return true;
}

bool STONE::subAmount(int amount)
{
	if ((this->amount - amount) < 0)
		return false;

	this->amount -= amount;
	return true;
}