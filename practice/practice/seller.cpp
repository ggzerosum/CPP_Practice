#include "includes.h"

namespace My_NameSpace
{
	SELLER::SELLER(int money)
		:m_iMoney(money), m_cApples(Sellers_Init_NumOfApples, PriceOfApples) // 선언과 초기화를 동시에.
	{
		//m_iMoney = money; //선언 후 초기화.
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