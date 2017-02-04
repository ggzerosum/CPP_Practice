#include "includes.h"

namespace My_NameSpace
{
	void BuyApples(CUSTOMER &customer, SELLER &seller)
	{
		int iNum;

		cout << "구입할 사과 갯수: ";
		cin >> iNum;

		customer.BuyApples(seller, iNum);
	}
}