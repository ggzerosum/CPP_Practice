#include "includes.h"

namespace My_NameSpace
{
	void CUSTOMER::Init(void)
	{
		m_cApples.Init(0, PriceOfApples);
		m_iMoney = Customers_Init_Money;
	}

	void CUSTOMER::BuyApples(SELLER &seller, int num)
	{
		int CurNum = m_cApples.GetNum();
		int price = m_cApples.GetPrice();
		int payment = num * price;

		if (payment > m_iMoney)
		{
			cout << "고객의 소지금이 부족합니다." << endl;
			return;
		}

		if (seller.SaleApples(num))
		{
			m_cApples.SetNum(CurNum + num);
			m_iMoney -= payment;
			cout << "거래를 성공적으로 마쳤습니다." << endl;
		}
	}

	void CUSTOMER::ShowState(void) const
	{
		cout << "<고객 현황>" << endl;
		cout << "사과 갯수: " << m_cApples.GetNum() << endl;
		cout << "소지금: " << m_iMoney << endl;
	}
}