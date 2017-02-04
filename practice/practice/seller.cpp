#include "includes.h"

namespace My_NameSpace
{
	void SELLER::Init(void)
	{
		m_cApples.Init(Sellers_Init_NumOfApples, PriceOfApples);
		m_iMoney = Sellers_Init_Money;
	}

	bool SELLER::SaleApples(int num)
	{
		int CurNum = m_cApples.GetNum();
		int price = m_cApples.GetPrice();
		int Profit = price * num;

		if (num > CurNum)
		{
			cout << "사과 장수의 사과가 부족합니다." << endl;
			return false;
		}

		m_cApples.SetNum(CurNum - num);
		m_iMoney += Profit;

		return true;
	}

	void SELLER::ShowState(void) const
	{
		cout << "<사과 장수 현황>" << endl;
		cout << "사과 보유량: " << m_cApples.GetNum() << endl;
		cout << "소지금: " << m_iMoney << "원" << endl;
	}
}