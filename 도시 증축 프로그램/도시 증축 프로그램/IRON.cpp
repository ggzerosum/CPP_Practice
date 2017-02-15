#include "all_includes.h"

const char IRON::name[5] = "°­Ã¶";
const int IRON::price = PriceOfIron;

IRON::IRON()
	:amount(0)
{
}

IRON::IRON(int amount)
{
	if (amount < 0)
		amount = 0;

	this->amount = amount;
}

IRON::~IRON()
{
}

const char* IRON::getName(void)
{
	return name;
}

int IRON::getPrice(void)
{
	return price;
}

int IRON::getAmount(void)
{
	return amount;
}

bool IRON::addAmount(int amount)
{
	if (amount < 0)
		return false;

	this->amount += amount;
	return true;
}

bool IRON::subAmount(int amount)
{
	if ((this->amount - amount) < 0)
		return false;

	this->amount -= amount;
	return true;
}