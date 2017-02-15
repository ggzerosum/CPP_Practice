#include "all_includes.h"

void main(void)
{
	CITY my_city(10000, 1000, 1000000, 100, 100, 100);
	TRADE my_trader(1000, 1000, 1000);

	my_city.ShowInfo();
	my_trader.SellToCity(Enums::IRON, my_city, 20);
	
	my_city.Build(Enums::TOWN_HALL);
	my_city.ShowInfo();

	my_city.Build(Enums::TOWN_HALL);
	my_city.ShowInfo();

	my_city.Build(Enums::TOWN_HALL);
	my_city.ShowInfo();
}