#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;

	ns::SELLER Apple_Seller;
	Apple_Seller.Init();

	ns::CUSTOMER Hans;
	Hans.Init();

	ns::BuyApples(Hans, Apple_Seller);

	Apple_Seller.ShowState();
	Hans.ShowState();
}