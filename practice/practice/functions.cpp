#include "includes.h"

namespace My_NameSpace
{
	void BuyApples(CUSTOMER &customer, SELLER &seller)
	{
		int iNum;

		cout << "������ ��� ����: ";
		cin >> iNum;

		customer.BuyApples(seller, iNum);
	}
}