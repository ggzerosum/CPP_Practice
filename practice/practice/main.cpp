#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;

	/*
	ns::SELLER Apple_Seller;
	ns::CUSTOMER Hans;

	ns::BuyApples(Hans, Apple_Seller);

	Apple_Seller.ShowState();
	Hans.ShowState();
	*/

	ns::SELLER* p_Seller = new ns::SELLER(1000);
	ns::CUSTOMER* p_Customer = new ns::CUSTOMER(100);

	ns::BuyApples(*p_Customer, *p_Seller);
	p_Seller->ShowState();
	p_Customer->ShowState();
}